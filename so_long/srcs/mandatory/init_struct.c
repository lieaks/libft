/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:45:19 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 19:35:32 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	new_map(t_map *m)
{
	m->nb_col = 0;
	m->nb_row = 0;
	m->nb_item = 0;
	m->img_size = IMG_SIZE;
	m->map_str = NULL;
	m->map = NULL;
	m->mlx_ptr = NULL;
	m->mlx_win = NULL;
	m->nb_mov = 0;
	m->nb_item = 0;
	m->pos_x = 0;
	m->pos_y = 0;
	m->on_exit = 0;
	m->stance = DOWN;
}

void	new_sprite_player(t_map *m)
{
	m->sprite.player_down1 = NULL;
	m->sprite.player_down2 = NULL;
	m->sprite.player_down3 = NULL;
	m->sprite.player_down4 = NULL;
	m->sprite.player_up1 = NULL;
	m->sprite.player_up2 = NULL;
	m->sprite.player_up3 = NULL;
	m->sprite.player_up4 = NULL;
	m->sprite.player_right1 = NULL;
	m->sprite.player_right2 = NULL;
	m->sprite.player_right3 = NULL;
	m->sprite.player_right4 = NULL;
}

void	new_sprite(t_map *m)
{
	m->sprite.wall = NULL;
	m->sprite.floor = NULL;
	m->sprite.coin1 = NULL;
	m->sprite.coin2 = NULL;
	m->sprite.coin3 = NULL;
	m->sprite.coin4 = NULL;
	m->sprite.coin5 = NULL;
	m->sprite.coin6 = NULL;
	m->sprite.exit1 = NULL;
	m->sprite.exit2 = NULL;
	m->sprite.exit3 = NULL;
	m->sprite.exit4 = NULL;
	m->sprite.exit5 = NULL;
	m->sprite.exit6 = NULL;
	m->sprite.exit7 = NULL;
	m->sprite.coin1 = NULL;
	m->sprite.coin2 = NULL;
	m->sprite.coin3 = NULL;
	m->sprite.coin4 = NULL;
	m->sprite.coin5 = NULL;
	m->sprite.coin6 = NULL;
	new_sprite_player(m);
}

void	new_err_map(t_map *m)
{
	m->err.row_len = 0;
	m->err.borders = 0;
	m->err.item = 0;
	m->err.pos = 0;
	m->err.ex = 0;
	m->err.character = 0;
	m->err.inv_map = 0;
}

void	search_pos(t_map *m)
{
	int	x;
	int	y;

	x = 0;
	while (m->map[x])
	{
		y = 0;
		while (m->map[x][y])
		{
			if (m->map[x][y] == 'P')
			{
				m->pos_x = x;
				m->pos_y = y;
			}
			y++;
		}
		x++;
	}
}
