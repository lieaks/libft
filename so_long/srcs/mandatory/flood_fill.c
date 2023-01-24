/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:45:03 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 15:18:53 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(int x, int y, t_map *m)
{
	if (m->map[x][y] == '1')
		return ;
	m->map[x][y] = '1';
	flood_fill(x + 1, y, m);
	flood_fill(x - 1, y, m);
	flood_fill(x, y + 1, m);
	flood_fill(x, y - 1, m);
}
