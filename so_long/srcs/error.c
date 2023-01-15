/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:31:12 by dly               #+#    #+#             */
/*   Updated: 2023/01/14 12:21:18 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_msg_err(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

void	print_err_map(t_err *err)
{
	if (err->borders)
		write(2, "Invalid borders.\n", 18);
	if (err->row_len)
		write(2, "Map must be rectangle!\n", 24);
	if (err->item == 0)
		write(2, "No collectible\n", 16);
	if (err->ex != 1)
		write(2, "Invalid exit\n", 14);
	if (err->pos != 1)
		write(2, "Invalid position\n", 18);
	if (err->character)
		write(2, "Invalid character\n", 19);
	if (err->inv_map)
		write(2, "Error\nInvalid map\n",19);
}

