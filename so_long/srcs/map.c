/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:52:08 by dly               #+#    #+#             */
/*   Updated: 2023/01/14 17:51:55y dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	new_map(t_map *m)
{
	// m = malloc(sizeof(t_map));
	// if (!m)
	// 	exit_msg_err("Error malloc new_map\n");
	m->nb_col = 0;
	m->nb_row = 0;
	m->nb_item = 0;
	m->map_str = NULL;
	m->map = NULL;
}

void	new_err_map(t_map *m, t_err *err_map)
{
	// err_map = malloc(sizeof(t_err));
	// if (!err_map)
	// {
	// 	free(m);
	// 	exit_msg_err("Error malloc err_map\n");
	// }
	err_map->borders = 0;
	err_map->item = 0;
	err_map->pos = 0;
	err_map->ex = 0;
}

void	check_map(t_map *m, char **av)
{
	t_err	err_map;
	
	m->map_str = NULL;
	m->map = NULL;
	m->fd = open_file(av[1]);
	new_map(m);
	new_err_map(m, &err_map);
	read_map(m);
	check_layers(m, &err_map);
	free_matrix(m->map);
}

void	read_map(t_map *m)
{
	char	*line;
	
	while (1)
	{
		line = get_next_line(m->fd, 0);
		
		if (!line)
		{
			if (!m->nb_row)
				exit_msg_err("File is empty\n");
			break;
		}
		m->map_str = ft_strjoin_free(m->map_str, line);
		m->nb_row++;
	}
	m->map = ft_split(m->map_str, '\n');
	if (!m->map)
	{
		free(m->map);
		exit_msg_err("Error malloc\n");
	}
	free(m->map_str);
	// return (map);
}

int	count_char(char *str, char c)
{
	int	res;
	int	i;
	
	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

void	check_layers(t_map *m, t_err *err)
{
	int	i;
	
	i = 0;
	while (m->map[i])
	{
		check_line(i, m->map[i], m, err);
		i++;
	}
	print_err_map(err);
}

void	check_line(int i, char *line, t_map *m, t_err *err)
{
	if (m->nb_col == 0)
		m->nb_col = ft_strlen(line);
	if ((int)ft_strlen(line) != m->nb_col && i != m->nb_col)
		err->row_len = 1;
	if ((i == 0 || i == m->nb_row - 1) && count_char(line, '1') != m->nb_col)
		err->borders = 1;
	if (line[0] != '1' || line [m->nb_col - 1] != '1')
		err->borders = 1;
	err->item += count_char(line, 'C');
	err->ex += count_char(line, 'E');
	err->pos += count_char(line, 'P');
}

void	print_err_map(t_err *err)
{
	if (err->borders)
		write(2, "Invalid borders.\n", 18);
	if (err->row_len)
		write(2, "Map must be rectangle!\n", 24);
	if (err->item == 0)
		write(2, "No collectible\n", 16);
	if (err->ex != 1)
		write(2, "Invalid exit\n", 14);
	if (err->pos != 1)
		write(2, "Invalid position\n", 18);
}