/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_mob_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:39:48 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 18:15:51 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	anim_mob(t_map *m, int i, int x, int y)
{
	if (!(i % 5000))
	{	
		if (!m->on_exit)
			print_sprite(m, m->sprite.floor, x, y);
		if (i == 0)
			print_sprite(m, m->sprite.mob1, x, y);
		else if (i == 5000)
			print_sprite(m, m->sprite.mob2, x, y);
		else if (i == 10000)
			print_sprite(m, m->sprite.mob2, x, y);
		else if (i == 15000)
			print_sprite(m, m->sprite.mob3, x, y);
		else if (i == 20000)
			print_sprite(m, m->sprite.mob3, x, y);
		else if (i == 25000)
			print_sprite(m, m->sprite.mob4, x, y);
		else if (i == 30000)
			print_sprite(m, m->sprite.mob4, x, y);
		else if (i == 35000)
			print_sprite(m, m->sprite.mob4, x, y);
		mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
	}
}
