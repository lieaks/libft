/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:02:28 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 16:56:47 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	key_hook(int keycode, t_map *m)
{
	if (keycode == ESCAPE)
		end_game(m);
	if (keycode == W || keycode == UP)
		move(m, -1, 0, UP);
	if (keycode == A || keycode == LEFT)
		move(m, 0, -1, LEFT);
	if (keycode == S || keycode == DOWN)
		move(m, 1, 0, DOWN);
	if (keycode == D || keycode == RIGHT)
		move(m, 0, 1, RIGHT);
	return (0);
}

void	print_nb_mov(t_map *m)
{
	char	*move;

	move = ft_itoa(m->nb_mov);
	if (!move)
	{
		ft_putstr_fd("Error\nmalloc itoa.\n", 2);
		end_game(m);
	}
	mlx_string_put(m->mlx_ptr, m->mlx_win, 50, 20, 0xff0000, move);
	free(move);
}

void	move_stance(t_map *m)
{
	if (!((m->map[m->pos_x][m->pos_y]) == 'E'))
		print_sprite(m, m->sprite.floor, m->pos_x, m->pos_y);
	if (m->stance == DOWN || m->stance == LEFT)
		print_sprite(m, m->sprite.player_down1, m->pos_x, m->pos_y);
	if (m->stance == UP)
		print_sprite(m, m->sprite.player_up1, m->pos_x, m->pos_y);
	if (m->stance == RIGHT)
		print_sprite(m, m->sprite.player_right1, m->pos_x, m->pos_y);
}

void	move(t_map *m, int move_x, int move_y, int stance)
{
	if (m->map[m->pos_x + move_x][m->pos_y + move_y] != '1')
	{
		m->stance = stance;
		if (m->map[m->pos_x + move_x][m->pos_y + move_y] == 'M')
			end_game(m);
		if (m->map[m->pos_x + move_x][m->pos_y + move_y] == 'C')
			m->nb_item--;
		print_sprite(m, m->sprite.floor, m->pos_x, m->pos_y);
		if (m->map[m->pos_x + move_x][m->pos_y + move_y] == 'E')
			m->on_exit = 1;
		if (m->map[m->pos_x + move_x][m->pos_y + move_y] != 'E')
		{
			m->on_exit = 0;
			m->map[m->pos_x + move_x][m->pos_y + move_y] = 'P';
		}
		if (m->map[m->pos_x][m->pos_y] != 'E')
			m->map[m->pos_x][m->pos_y] = '0';
		m->pos_x += move_x;
		m->pos_y += move_y;
		m->nb_mov++;
		move_stance(m);
		if (m->map[m->pos_x][m->pos_y] == 'E' && m->nb_item == 0)
			end_game(m);
	}
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
}
