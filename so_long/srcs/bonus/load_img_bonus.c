/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:49:49 by dly               #+#    #+#             */
/*   Updated: 2023/01/23 21:29:16 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_player_down(t_map *m)
{
	m->sprite.player_down1 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringdown1.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_down1)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_down2 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringdown2.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_down2)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_down3 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringdown3.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_down3)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_down4 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringdown4.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_down4)
		exit_msg_err(m, "Error\nIMG load failed\n");
}

void	set_player_right(t_map *m)
{
	m->sprite.player_right1 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringright1.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_right1)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_right2 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringright2.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_right2)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_right3 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringright3.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_right3)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_right4 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringright4.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_right4)
		exit_msg_err(m, "Error\nIMG load failed\n");
}

void	set_player_up(t_map *m)
{
	m->sprite.player_up1 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringup1.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_down1)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_up2 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringup2.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_up2)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_up3 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringup3.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_up3)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.player_up4 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/poringup4.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.player_up4)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.exit7 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/exit7.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit7)
		exit_msg_err(m, "Error\nIMG load failed\n");
}

void	set_coin(t_map *m)
{
	m->sprite.coin1 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/plant1.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.coin1)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.coin2 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/plant2.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.coin2)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.coin3 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/plant3.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.coin3)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.coin4 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/plant4.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.coin4)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.coin5 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/plant5.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.coin5)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.coin6 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/plant6.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.coin6)
		exit_msg_err(m, "Error\nIMG load failed\n");
}

void	set_exit(t_map *m)
{
	m->sprite.exit1 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/exit1.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit1)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.exit2 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/exit2.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit2)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.exit3 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/exit3.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit3)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.exit4 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/exit4.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit4)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.exit5 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/exit5.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit5)
		exit_msg_err(m, "Error\nIMG load failed\n");
	m->sprite.exit6 = mlx_xpm_file_to_image(m->mlx_ptr,
			"./sprites/exit6.xpm", &m->img_size, &m->img_size);
	if (!m->sprite.exit6)
		exit_msg_err(m, "Error\nIMG load failed\n");
}
