/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:31:12 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 16:43:20 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	exit_msg_err(t_map *m, char *err)
{
	write(2, err, ft_strlen(err));
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
	exit(EXIT_FAILURE);
}

void	print_err_map(t_map *m)
{
	if (m->err.borders)
		exit_msg_err(m, INV_BORDERS);
	if (m->err.row_len)
		exit_msg_err(m, INV_REC);
	if (m->err.item == 0)
		exit_msg_err(m, INV_COLLECTIBLE);
	if (m->err.ex != 1)
		exit_msg_err(m, INV_EXIT);
	if (m->err.pos != 1)
		exit_msg_err(m, INV_POS);
	if (m->err.character)
		exit_msg_err(m, INV_CHAR);
	if (m->err.inv_map)
		exit_msg_err(m, INV_MAP);
}
