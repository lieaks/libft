/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:59:07 by dly               #+#    #+#             */
/*   Updated: 2023/01/12 18:41:17 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_elem
{
	char	*line;
	int		idx;
	char	*prev;
	char	*next;
}			t_elem;

typedef struct s_map
{
	int		file;
	t_elem	*top_map;
	t_elem	*bottom_map;	
	
}	t_map;

void	exit_msg_err(char *err);
void	init_map(t_map **map);
t_elem	*new_node(int nb);

#endif