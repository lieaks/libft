/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:52:08 by dly               #+#    #+#             */
/*   Updated: 2023/01/16 20:42:47 by dly              ###   ########.fr       */
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
	m->mlx_win = mlx_new_window(m->mlx_ptr, m->nb_col * m->img_size, 
		m->nb_row * m->img_size ,"so_long");
	if (!m->mlx_win)
	{
		free_matrix(m->map);
		free(m->mlx_ptr);
		exit_msg_err("Error\nInit mlx win failed\n");
	}
	new_img(m);
	render_frame(m);
	mlx_loop(m->mlx_ptr);
}

void	render_frame(t_map *m)
{
	put_floor(m);
	put_others(m);
}

void	put_floor(t_map *m)
{
	int	x;
	int y;

	x = 0;
	while (m->map[x])
	{
		y = 0;
		while (m->map[x][y])
		{
			if (m->map[x][y] == '1')
				print_sprite(m, m->sprite.wall, x, y);
			else
				print_sprite(m, m->sprite.floor, x, y);
			y++;
		}
		x++;
	}
}

void	put_others(t_map *m)
{
	int	x;
	int y;

	x = 0;
	while (m->map[x])
	{
		y = 0;
		while (m->map[x][y])
		{
			if (m->map[x][y] == 'C')
				print_sprite(m, m->sprite.collectible, x, y);
			// if (m->map[x][y] == 'E')
			// 	print_sprite(m, m->sprite.floor, x, y);
			// if (m->map[x][y] == 'P')
			// 	print_sprite(m, m->sprite.floor, x, y);
			y++;
		}
		x++;
	}
}



void	print_sprite(t_map *m, void *img, int x, int y)
{
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, 
		img, m->img_size * y, m->img_size * x);
}

void	new_img(t_map *m)
{
	m->sprite.floor = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/floor.xpm", &m->img_size, &m->img_size);
	m->sprite.wall = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/wall.xpm", &m->img_size, &m->img_size);
	m->sprite.collectible = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/collectible.xpm", &m->img_size, &m->img_size);
}