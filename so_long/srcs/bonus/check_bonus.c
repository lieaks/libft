/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:23:25 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 16:10:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	check_layers(t_map *m)
{
	int	i;

	i = 0;
	while (m->map[i])
	{
		check_line(i, m->map[i], m);
		i++;
	}
}

void	check_line(int i, char *line, t_map *m)
{
	int	idx;

	idx = 0;
	if (m->nb_col == 0)
		m->nb_col = ft_strlen(line);
	if ((int)ft_strlen(line) != m->nb_col)
		m->err.row_len = 1;
	if ((i == 0 || i == m->nb_row - 1) && ft_count_char(line, '1') != m->nb_col)
		m->err.borders = 1;
	if (line[0] != '1' || line[m->nb_col - 1] != '1')
		m->err.borders = 1;
	m->err.item += ft_count_char(line, 'C');
	m->nb_item = m->err.item;
	m->err.ex += ft_count_char(line, 'E');
	m->err.pos += ft_count_char(line, 'P');
	m->nb_mob += ft_count_char(line, 'M');
	while (line[idx])
	{
		if (!ft_strchr("01CEPM", line[idx]))
			m->err.character = 1;
		idx++;
	}
}
