/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:33:09 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 18:44:07 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	anim_coin(t_map *m, int i, int x, int y)
{
	if (!(i % 5000))
	{
		print_sprite(m, m->sprite.floor, x, y);
		if (i == 0)
			print_sprite(m, m->sprite.coin1, x, y);
		else if (i == 5000)
			print_sprite(m, m->sprite.coin2, x, y);
		else if (i == 10000)
			print_sprite(m, m->sprite.coin3, x, y);
		else if (i == 15000)
			print_sprite(m, m->sprite.coin4, x, y);
		else if (i == 20000)
			print_sprite(m, m->sprite.coin5, x, y);
		else if (i == 25000)
			print_sprite(m, m->sprite.coin6, x, y);
		else if (i == 30000)
			print_sprite(m, m->sprite.coin1, x, y);
		else if (i == 35000)
			print_sprite(m, m->sprite.coin1, x, y);
		mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
	}
}

void	anim_exit_close(t_map *m, int i, int x, int y)
{
	if (!(i % 5000))
	{
		print_sprite(m, m->sprite.floor, x, y);
		if (i == 0)
			print_sprite(m, m->sprite.exit1, x, y);
		else if (i == 5000)
			print_sprite(m, m->sprite.exit2, x, y);
		else if (i == 10000)
			print_sprite(m, m->sprite.exit3, x, y);
		else if (i == 15000)
			print_sprite(m, m->sprite.exit4, x, y);
		else if (i == 20000)
			print_sprite(m, m->sprite.exit5, x, y);
		else if (i == 25000)
			print_sprite(m, m->sprite.exit6, x, y);
		else if (i == 30000)
			print_sprite(m, m->sprite.exit7, x, y);
		else if (i == 35000)
			print_sprite(m, m->sprite.exit7, x, y);
		mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
	}
}

void	anim_exit_open(t_map *m, int i, int x, int y)
{
	if (!(i % 10000))
	{
		print_sprite(m, m->sprite.floor, x, y);
		if (i == 0)
			print_sprite(m, m->sprite.exit3, x, y);
		else if (i == 10000)
			print_sprite(m, m->sprite.exit4, x, y);
		else if (i == 20000)
			print_sprite(m, m->sprite.exit3, x, y);
		else if (i == 30000)
			print_sprite(m, m->sprite.exit4, x, y);
		mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
	}
}

void	animation_all(t_map *m, int t, int y, int x)
{
	if (m->map[y][x] == 'C')
		anim_coin(m, t, y, x);
	if (m->map[y][x] == 'E' && m->nb_item)
		anim_exit_close(m, t, y, x);
	if (m->map[y][x] == 'E' && !m->nb_item)
		anim_exit_open(m, t, y, x);
	if (m->map[y][x] == 'M')
		anim_mob(m, t, y, x);
	if (m->map[y][x] == 'P' || (m->map[y][x] == 'E' && m->on_exit))
	{
		if (m->stance == UP)
			anim_player_up(m, t, y, x);
		if (m->stance == RIGHT)
			anim_player_right(m, t, y, x);
		if (m->stance == DOWN || m->stance == LEFT)
			anim_player_down(m, t, y, x);
	}
}

int	update(t_map *m)
{
	static int	t;
	int			x;
	int			y;

	x = -1;
	while (++x < m->nb_col)
	{
		y = -1;
		while (++y < m->nb_row)
			animation_all(m, t, y, x);
		print_nb_mov(m);
	}
	t++;
	if (t > 35000)
		t = 0;
	return (1);
}
