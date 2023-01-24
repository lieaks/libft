/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_player_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:52:57 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 18:16:39 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	anim_player_down(t_map *m, int i, int x, int y)
{
	if (!(i % 5000))
	{	
		if (!m->on_exit)
			print_sprite(m, m->sprite.floor, x, y);
		if (i == 0)
			print_sprite(m, m->sprite.player_down1, x, y);
		else if (i == 5000)
			print_sprite(m, m->sprite.player_down1, x, y);
		else if (i == 10000)
			print_sprite(m, m->sprite.player_down2, x, y);
		else if (i == 15000)
			print_sprite(m, m->sprite.player_down2, x, y);
		else if (i == 20000)
			print_sprite(m, m->sprite.player_down3, x, y);
		else if (i == 25000)
			print_sprite(m, m->sprite.player_down4, x, y);
		else if (i == 30000)
			print_sprite(m, m->sprite.player_down4, x, y);
		else if (i == 35000)
			print_sprite(m, m->sprite.player_down1, x, y);
		mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
	}
}

void	anim_player_right(t_map *m, int i, int x, int y)
{
	if (!(i % 5000))
	{	
		if (!m->on_exit)
			print_sprite(m, m->sprite.floor, x, y);
		if (i == 0)
			print_sprite(m, m->sprite.player_right1, x, y);
		else if (i == 5000)
			print_sprite(m, m->sprite.player_right2, x, y);
		else if (i == 10000)
			print_sprite(m, m->sprite.player_right2, x, y);
		else if (i == 15000)
			print_sprite(m, m->sprite.player_right2, x, y);
		else if (i == 20000)
			print_sprite(m, m->sprite.player_right3, x, y);
		else if (i == 25000)
			print_sprite(m, m->sprite.player_right4, x, y);
		else if (i == 30000)
			print_sprite(m, m->sprite.player_right4, x, y);
		else if (i == 35000)
			print_sprite(m, m->sprite.player_right1, x, y);
		mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
	}
}

void	anim_player_up(t_map *m, int i, int x, int y)
{
	if (!(i % 5000))
	{	
		if (!m->on_exit)
			print_sprite(m, m->sprite.floor, x, y);
		if (i == 0)
			print_sprite(m, m->sprite.player_up1, x, y);
		else if (i == 5000)
			print_sprite(m, m->sprite.player_up2, x, y);
		else if (i == 10000)
			print_sprite(m, m->sprite.player_up2, x, y);
		else if (i == 15000)
			print_sprite(m, m->sprite.player_up2, x, y);
		else if (i == 20000)
			print_sprite(m, m->sprite.player_up3, x, y);
		else if (i == 25000)
			print_sprite(m, m->sprite.player_up4, x, y);
		else if (i == 30000)
			print_sprite(m, m->sprite.player_up4, x, y);
		else if (i == 35000)
			print_sprite(m, m->sprite.player_up1, x, y);
		mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
	}
}
