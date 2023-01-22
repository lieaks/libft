/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:02:28 by dly               #+#    #+#             */
/*   Updated: 2023/01/21 18:56:01 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_map *m)
{
	if (keycode == ESCAPE)
		end_game(m);
	if (keycode == W || keycode == UP)
		move(m, -1, 0);	
	if (keycode == A || keycode == LEFT)
		move(m, 0, -1);	
	if (keycode == S || keycode == DOWN)
		move(m, 1, 0);	
	if (keycode == D || keycode == RIGHT)
		move(m, 0, 1);	
	return (0);
}

void	print_nb_mov(t_map *m)
{
	char	move;

	move = ft_itoa(m->nb_mov);
	if (!move)		
	{
		ft_putstr_fd("Error\nmalloc itoa.\n", 2);
		end_game(m);
	}
	mlx_string_put(m->mlx_ptr, m->mlx_win, 0, 0, #000000, move);
	free(move);
}

void	move(t_map *m, int move_x, int move_y)
{
	if (m->map[m->pos_x + move_x][m->pos_y + move_y] != '1')
	{
		if (m->map[m->pos_x + move_x][m->pos_y + move_y] == 'C')
			m->nb_item--;	
		print_sprite(m, m->sprite.floor, m->pos_x, m->pos_y);
		if (!m->map[m->pos_x + move_x][m->pos_y + move_y] == 'E')
			m->map[m->pos_x + move_x][m->pos_y + move_y] = 'P';
		m->map[m->pos_x][m->pos_y] = '0';
		m->pos_x += move_x;
		m->pos_y += move_y;
		m->nb_mov++;
		ft_putstr_fd("Movements : ", 1);
		ft_putnbr_fd(m->nb_mov, 1);
		ft_putstr_fd("\n", 1);
		if ((!(m->map[m->pos_x][m->pos_y]) == 'E'))
			print_sprite(m, m->sprite.floor, m->pos_x, m->pos_y);
		print_sprite(m, m->sprite.perso, m->pos_x, m->pos_y);
		if (m->map[m->pos_x][m->pos_y] == 'E' && m->nb_item == 0)
			end_game(m);
	}
	print_nb_mov(m);
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0 ,0 );
}

