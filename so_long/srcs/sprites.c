/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:35 by dly               #+#    #+#             */
/*   Updated: 2023/01/21 17:43:24 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data_img *m, int y, int x, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_l + x * (m->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	get_color_pixel(void *img, int x, int y)
{
	char *addr;
	char *src;
	unsigned int	color;
	int	pos;
	int	bpp;
	int	line_l;
	int endian;

	addr = mlx_get_data_addr(img, &bpp, &line_l, &endian);
	src = addr + (y * line_l + x * (bpp / 8));
	color = *(unsigned int*)src;
	return (color);
}

void	print_sprite(t_map *m, void *img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->img_size)
	{
		j = 0;
		while (j < m->img_size)
		{
			m->sprite.color = get_color_pixel(img, i, j);
			if (!(m->sprite.color == (0xFF << 24)))
				my_mlx_pixel_put(&m->img, (x * m->img_size) + j, (y * m->img_size) + i, m->sprite.color);
			j++;
		}
		i++;
	}
	
}

void	put_standard_sprite(t_map *m)
{
	int	x;
	int y;

	x = 0;
	while (m->map[x])
	{
		y = 0;
		while (m->map[x][y])
		{
			print_sprite(m, m->sprite.floor, x, y);
			if (m->map[x][y] == '1')
				print_sprite(m, m->sprite.wall, x, y);
			if (m->map[x][y] == 'C')
				print_sprite(m, m->sprite.coin, x, y);
			// if (m->map[x][y] == 'E')
			// 	print_sprite(m, m->sprite.exit, x, y);
			if (m->map[x][y] == 'P')
				print_sprite(m, m->sprite.player, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0 ,0 );
}

void	set_sprite(t_map *m)
{
	m->sprite.floor = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/floor.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.floor)
		end_game(m);
	m->sprite.wall = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/wall.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.wall)
		end_game(m);
	m->sprite.coin = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/poring.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.coin)
		end_game(m);
	m->sprite.player = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/perso.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player)
		end_game(m);
	m->sprite.exit = mlx_xpm_file_to_image(m->mlx_ptr, "./sprites/exit.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit)
		end_game(m);
}
