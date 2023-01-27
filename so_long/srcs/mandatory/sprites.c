/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:01:35 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 19:23:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_mlx_pixel_put(t_data_img *m, int y, int x, int color)
{
	char	*dst;

	dst = m->addr + (y * m->line_l + x * (m->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color_pixel(void *img, int x, int y)
{
	t_data_img		tmp;
	unsigned int	color;
	char			*src;

	tmp.addr = mlx_get_data_addr(img, &tmp.bpp, &tmp.line_l, &tmp.endian);
	src = tmp.addr + (y * tmp.line_l + x * (tmp.bpp / 8));
	color = *(unsigned int *)src;
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
				my_mlx_pixel_put(&m->img, (x * m->img_size) + j,
					(y * m->img_size) + i, m->sprite.color);
			j++;
		}
		i++;
	}
}

void	put_standard_sprite(t_map *m)
{
	int	x;
	int	y;

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
				print_sprite(m, m->sprite.coin1, x, y);
			if (m->map[x][y] == 'E')
				print_sprite(m, m->sprite.exit4, x, y);
			if (m->map[x][y] == 'P')
				print_sprite(m, m->sprite.player_down1, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(m->mlx_ptr, m->mlx_win, m->img.img, 0, 0);
}

void	set_sprite(t_map *m)
{
	set_coin(m);
	set_exit(m);
	set_player_down(m);
	set_player_up(m);
	set_player_right(m);
	m->sprite.floor = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/floor.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.floor)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.wall = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/wall.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.wall)
		exit_msg_err(m, "Error\nIMG load failed\n");
}
