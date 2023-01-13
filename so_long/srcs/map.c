/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:52:08 by dly               #+#    #+#             */
/*   Updated: 2023/01/13 18:15:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	new_map(t_map *m)
{
	m->nb_col = 0;
	m->nb_row = 0;
	m->err_map->borders = 0;
}

char	**check_map(t_map *m, char **av)
{
	m->map_str = NULL;
	m->map = NULL;
	m->fd = open_file(av[1]);
	new_map(&m);
	read_map_str(&m);
}

void	read_map_str(t_map *m)
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
		// check_line(&m, line);
		m->map_str = ft_join(m->map_str, line);
		free(line);
		m->nb_row++;
	}
}

char	count_char(char *str, char c)
{
	int	res;

	res = 0;
	while (str)
	{
		if (*str == c)
			res++;
	}
	return (res);
}

void	check_line(t_map *m, char *line)
{
	if (m->nb_col == 0)
		m->nb_col = ft_strlen(line);
	if (m->nb_row == 0 || !line)
		m->err_map->borders = 1;
	if (!line)
	{
		
	}
	else
	w
	
}