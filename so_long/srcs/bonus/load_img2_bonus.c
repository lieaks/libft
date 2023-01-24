/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:33:42 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 16:44:08 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	set_mob(t_map *m)
{
	m->sprite.mob1 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/mob1.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.mob1)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.mob2 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/mob2.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.mob2)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.mob3 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/mob3.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.mob3)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.mob4 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/mob4.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.mob4)
		exit_msg_err(m, "Error\nIMG load failed\n");
}
