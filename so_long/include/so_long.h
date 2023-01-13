/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:59:07 by dly               #+#    #+#             */
/*   Updated: 2023/01/13 17:09:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "get_next_line.h"
# include "libft.h"

// typedef struct s_elem
// {
// 	char	*line;
// 	int		idx;
// 	char	*prev;
// 	char	*next;
// }			t_elem;


typedef struct s_err
{
	bool	borders;
	bool	
}	t_err;

typedef struct s_map
{
	int		fd;
	char	*map_str;
	char	*map;
	int		nb_col;
	int		nb_row;
	t_err	*err_map;
		
}	t_map;

void	exit_msg_err(char *err);

#endif