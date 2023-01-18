/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:52:08 by dly               #+#    #+#             */
/*   Updated: 2023/01/18 18:05:17 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_matrix(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

char	**get_matrix(char *str)
{
	char	**matrix;

	matrix = ft_split(str, '\n');
	if (!matrix)
	{
		write(2, "Error\nMalloc in split failed\n", 30);
		return (NULL);
	}
	return (matrix);
}

void	check_map(t_map *m, char *file)
{
	t_err	err_map;
	
	new_map(m);
	new_err_map(m, &err_map);
	get_map_str(m, file);
	valid_map(m, &err_map);
	print_matrix(m->map);
	free(m->map_str);
	// free_matrix(m->map);
}

void	valid_map(t_map *m, t_err *err)
{
	m->map = get_matrix(m->map_str);
	if (!m->map)
		return ;
	check_layers(m, err);
	search_pos(m);
	flood_fill(m->pos_x, m->pos_y, m);
	err->inv_map = ft_strchrstr("PEC", m->map);
	print_err_map(err);
	free_matrix(m->map);
	m->map = get_matrix(m->map_str);
	if (!m->map)
		return ;
}

void	get_map_str(t_map *m, char *file)
{
	int		fd;
	char	*line;
	
	fd = open_file(file);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
		{
			if (!m->nb_row)
				exit_msg_err("File is empty\n");
			break;
		}
		m->map_str = ft_strjoin_free(m->map_str, line);
		m->nb_row++;
	}
	if (close(fd) < 0)
	{
		free(m->map_str);
		exit_msg_err("Error\nClosing file failed\n");
	}
}

void	render(t_map *m)
{
	m->mlx_ptr = mlx_init();
	if (!m->mlx_ptr)
	{
		free_matrix(m->map);
		exit_msg_err("Error\nInit mlx failed\n");
	}
	m->img.img = mlx_new_image(m->mlx_ptr, (m->img_size * m->nb_col),(m->img_size * m->nb_row));
	m->img.addr = mlx_get_data_addr(m->img.img, &m->img.bpp, &m->img.line_l, &m->img.endian);
	m->mlx_win = mlx_new_window(m->mlx_ptr, m->nb_col * m->img_size, 
		m->nb_row * m->img_size ,"so_long");
	if (!m->mlx_win)
	{
		free_matrix(m->map);
		free(m->mlx_ptr);
		exit_msg_err("Error\nInit mlx win failed\n");
	}
	set_sprite(m);
	put_standard_sprite(m);
	mlx_loop(m->mlx_ptr);
}

void	my_mlx_pixel_put(t_data_img *m, int y, int x, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_l + x * (m->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_color_pixel(void *img, int x, int y)
{
	char *addr;
	char *src;
	unsigned int	color;
	int	pos;
	int	bpp;
	int	line_l;
	int endian;

	addr = mlx_get_data_addr(img, &bpp, &line_l, &endian);
	src = addr + (y * line_l + x * (bpp / 8));
	color = *(unsigned int*)src;
	return (color);
}

void	print_sprite(t_map *m, void *img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->img_size)
	{
		j = 0;
		while (j < m->img_size)
		{
			m->sprite.color = get_color_pixel(img, i, j);
			if (!(m->sprite.color == (0xFF << 24)))
				my_mlx_pixel_put(&m->img, (x * m->img_size) + j, (y * m->img_size) + i, m->sprite.color);
			j++;
		}
		i++;
	}
	
}

void	put_standard_sprite(t_map *m)
{
	int	x;
	int y;

	x = 0;
	while (m->map[x])
	{
		y = 0;
		while (m->map[x][y])
		{
			print_sprite(m, m->sprite.floor, x, y);
			if (m->map[x][y] == '1')
				print_sprite(m, m->sprite.wall, x, y);
			if (m->map[x][y] == 'C')
				print_sprite(m, m->sprite.collectible, x, y);
			if (m->map[x][y] == 'E')
				print_sprite(m, m->sprite.collectible, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0 ,0 );
}

void	set_sprite(t_map *m)
{
	m->sprite.floor = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/floor.xpm", &m->img_size, &m->img_size);
	m->sprite.wall = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/wall.xpm", &m->img_size, &m->img_size);
	m->sprite.collectible = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/collectible.xpm", &m->img_size, &m->img_size);
}