/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:52:08 by dly               #+#    #+#             */
/*   Updated: 2023/01/21 21:50:33 by dly              ###   ########.fr       */
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
	mlx_key_hook(m->mlx_win, key_hook, m);
	mlx_hook(m->mlx_win, 17, 0, end_game, m->mlx_ptr);
	mlx_loop_hook(m->mlx_ptr, update, m);
	mlx_loop(m->mlx_ptr);
}

void	rot(t_map *m, int i, int x, int y)
{
	if (!(i % 2000))
	{
		print_sprite(m, m->sprite.floor, x, y);
	if (i == 0)
		print_sprite(m, m->sprite.collectible, x, y);
	else if (i == 2000)
		print_sprite(m, m->sprite.perso, x, y);
	else if (i == 4000)
		print_sprite(m, m->sprite.wall, x, y);
	else if (i == 6000)
		print_sprite(m, m->sprite.collectible, x, y);
	else if (i == 8000)
		print_sprite(m, m->sprite.wall, x, y);
	else if (i == 10000)
		print_sprite(m, m->sprite.perso, x, y);
	else if (i == 12000)
		print_sprite(m, m->sprite.collectible, x, y);
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0 ,0 );
	}
}

int	update(t_map *m)
{
	static int t;
	int	x;
	int y;

	x = 0;
	while (x < m->nb_col)
	{
		y = 0;
		while (y < m->nb_row)
		{
			if (m->map[y][x] == 'C')
			{
				rot(m, t, y, x);
			}
			// if (m->map[x][y] == 'E')
			// 	print_sprite(m, m->sprite.exit, x, y);
			y++;
		}
		x++;
	}
	t++;
	// printf("%d\n", t);
	if (t > 12000)
		t = 0;
}



int	end_game(t_map *m)
{
	if (m->map)
		free_matrix(m->map);	
	mlx_destroy_image(m->mlx_ptr, m->img.img);
	free(m->sprite.floor);
	mlx_clear_window(m->mlx_ptr, m->mlx_win);
	mlx_destroy_window(m->mlx_ptr, m->mlx_win);
	mlx_destroy_display(m->mlx_ptr);
	
	free(m->mlx_ptr);
	exit(0);
	return (0);
}

