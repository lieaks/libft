/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:30:48 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 17:37:59 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	get_map_str(t_map *m, char *file)
{
	int		fd;
	char	*line;

	fd = open_file(m, file);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
		{
			if (!m->nb_row)
				exit_msg_err(m, "Error\nFile is empty\n");
			break ;
		}
		m->map_str = ft_strjoin_free(m->map_str, line);
		m->nb_row++;
	}
	if (close(fd) < 0)
		exit_msg_err(m, "Error\nClosing file failed\n");
}

char	**get_matrix(char *str)
{
	char	**matrix;

	matrix = ft_split(str, '\n');
	if (!matrix)
		return (NULL);
	return (matrix);
}

void	check_map(t_map *m, char *file)
{
	new_map(m);
	new_err_map(m);
	new_sprite(m);
	get_map_str(m, file);
	m->map = get_matrix(m->map_str);
	if (!m->map)
		exit_msg_err(m, "Error\nMalloc in split failed\n");
	check_layers(m);
	search_pos(m);
	print_err_map(m);
	flood_fill(m->pos_x, m->pos_y, m);
	m->err.inv_map = ft_strchrstr("PEC", m->map);
	print_err_map(m);
	free_matrix(m->map);
	m->map = get_matrix(m->map_str);
	if (!m->map)
		exit_msg_err(m, "Error\nMalloc in split failed\n");
}

void	render(t_map *m)
{
	m->mlx_ptr = mlx_init();
	if (!m->mlx_ptr)
		exit_msg_err(m, "Error\nInit mlx failed\n");
	m->img.img = mlx_new_image(m->mlx_ptr, (m->img_size * m->nb_col),
			(m->img_size * m->nb_row));
	if (!m->img.img)
		exit_msg_err(m, "Error\nNew IMG failed\n");
	m->img.addr = mlx_get_data_addr(m->img.img, &m->img.bpp,
			&m->img.line_l, &m->img.endian);
	if (!m->img.addr)
		exit_msg_err(m, "Error\nGet IMG addr failed\n");
	m->mlx_win = mlx_new_window(m->mlx_ptr, m->nb_col * m->img_size,
			m->nb_row * m->img_size, "so_long");
	if (!m->mlx_win)
		exit_msg_err(m, "Error\nNew mlx win failed\n");
	set_sprite(m);
	put_standard_sprite(m);
	mlx_key_hook(m->mlx_win, key_hook, m);
	mlx_hook(m->mlx_win, 17, 0, end_game, m);
	mlx_loop_hook(m->mlx_ptr, update, m);
	mlx_loop(m->mlx_ptr);
	end_game(m);
}
