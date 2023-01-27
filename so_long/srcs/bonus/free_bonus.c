/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:06:07 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 18:41:59 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	free_matrix(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_img_player(t_map *m)
{
	if (m->sprite.player_down1)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_down1);
	if (m->sprite.player_down2)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_down2);
	if (m->sprite.player_down3)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_down3);
	if (m->sprite.player_down4)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_down4);
	if (m->sprite.player_up1)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_up1);
	if (m->sprite.player_up2)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_up2);
	if (m->sprite.player_up3)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_up3);
	if (m->sprite.player_up4)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_up4);
	if (m->sprite.player_right1)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_right1);
	if (m->sprite.player_right2)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_right2);
	if (m->sprite.player_right3)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_right3);
	if (m->sprite.player_right4)
		mlx_destroy_image(m->mlx_ptr, m->sprite.player_right4);
}

void	free_img_exit(t_map *m)
{
	if (m->sprite.exit1)
		mlx_destroy_image(m->mlx_ptr, m->sprite.exit1);
	if (m->sprite.exit2)
		mlx_destroy_image(m->mlx_ptr, m->sprite.exit2);
	if (m->sprite.exit3)
		mlx_destroy_image(m->mlx_ptr, m->sprite.exit3);
	if (m->sprite.exit4)
		mlx_destroy_image(m->mlx_ptr, m->sprite.exit4);
	if (m->sprite.exit5)
		mlx_destroy_image(m->mlx_ptr, m->sprite.exit5);
	if (m->sprite.exit6)
		mlx_destroy_image(m->mlx_ptr, m->sprite.exit6);
	if (m->sprite.exit7)
		mlx_destroy_image(m->mlx_ptr, m->sprite.exit7);
	if (m->sprite.mob1)
		mlx_destroy_image(m->mlx_ptr, m->sprite.mob1);
	if (m->sprite.mob2)
		mlx_destroy_image(m->mlx_ptr, m->sprite.mob2);
	if (m->sprite.mob3)
		mlx_destroy_image(m->mlx_ptr, m->sprite.mob3);
	if (m->sprite.mob4)
		mlx_destroy_image(m->mlx_ptr, m->sprite.mob4);
}

void	free_img(t_map *m)
{
	if (m->sprite.wall)
		mlx_destroy_image(m->mlx_ptr, m->sprite.wall);
	if (m->sprite.floor)
		mlx_destroy_image(m->mlx_ptr, m->sprite.floor);
	if (m->sprite.coin1)
		mlx_destroy_image(m->mlx_ptr, m->sprite.coin1);
	if (m->sprite.coin2)
		mlx_destroy_image(m->mlx_ptr, m->sprite.coin2);
	if (m->sprite.coin3)
		mlx_destroy_image(m->mlx_ptr, m->sprite.coin3);
	if (m->sprite.coin4)
		mlx_destroy_image(m->mlx_ptr, m->sprite.coin4);
	if (m->sprite.coin5)
		mlx_destroy_image(m->mlx_ptr, m->sprite.coin5);
	if (m->sprite.coin6)
		mlx_destroy_image(m->mlx_ptr, m->sprite.coin6);
	free_img_player(m);
	free_img_exit(m);
}

int	end_game(t_map *m)
{
	if (m->map)
		free_matrix(m->map);
	if (m->map_str)
		free(m->map_str);
	if (m->img.img)
		mlx_destroy_image(m->mlx_ptr, m->img.img);
	free_img(m);
	if (m->mlx_ptr && m->mlx_win)
		mlx_destroy_window(m->mlx_ptr, m->mlx_win);
	if (m->mlx_ptr)
	{
		mlx_destroy_display(m->mlx_ptr);
		free(m->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
