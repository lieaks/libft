/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:40 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 19:48:58 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	open_file(t_map *m, char *file)
{
	int	fd;

	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
	{
		if (m->map)
			free_matrix(m->map);
		if (m->map_str)
			free(m->map_str);
		ft_putstr_fd(INV_FILE, 2);
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		if (m->map)
			free_matrix(m->map);
		if (m->map_str)
			free(m->map_str);
		ft_putstr_fd("Error\nFile not found\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
