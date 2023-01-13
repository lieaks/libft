/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:51:40 by dly               #+#    #+#             */
/*   Updated: 2023/01/13 17:53:04 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_file(char *file)
{
	int	fd;

	if (!ft_strncmp(file, ".ber", ft_strlen(file)))
		exit_msg_err("Invalid file type, please use .ber\n");
	fd = open(file, O_RDONLY);
	if (!fd)
		exit_msg_err("File not found\n");
	return (fd);
}
