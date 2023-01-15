/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:52:08 by dly               #+#    #+#             */
/*   Updated: 2023/01/14 17:51:55y dly                ###   ########.fr       */
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
	// print_matrix(m->map);
	free(m->map_str);
	free_matrix(m->map);
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
	m->mlx_win = mlx_new_window(m->mlx_ptr, m->nb_col - 1 * IMG_WIDTH, 
		m->nb_row - 1 * IMG_HEIGHT ,"so_long");
	if (!m->mlx_win)
	{
		free_matrix(m->map);
		free(m->mlx_ptr);
	}
	render_frame(m);
	mlx_loop(m->mlx_ptr);
}

void	render_frame(t_map *m)
{
	put_floor(m);
}

void	put_floor(t_map *m)
{

}

void	print_sprite(t_map *m, void *img, int x, int y)
{
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, 
		img, IMG_WIDTH * x, IMG_HEIGHT * y);
}