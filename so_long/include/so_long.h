/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:59:07 by dly               #+#    #+#             */
/*   Updated: 2023/01/14 17:46:57 by dly              ###   ########.fr       */
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
	bool	row_len;
	int		item;
	int		ex;
	int		pos;
}	t_err;

typedef struct s_map
{
	int		fd;
	char	*map_str;
	char	**map;
	int		nb_col;
	int		nb_row;
	int		nb_item;
}	t_map;

void	exit_msg_err(char *err);
void	check_map(t_map *m, char **av);
void	read_map(t_map *m);
int		open_file(char *file);
void	free_matrix(char **tab);
void	check_layers(t_map *m, t_err *err);
void	check_line(int i, char *line, t_map *m, t_err *err);
void	print_err_map(t_err *err);

#endif