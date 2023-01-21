/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:59:07 by dly               #+#    #+#             */
/*   Updated: 2023/01/21 19:51:23 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "get_next_line.h"
# include "libft.h"
# include <mlx.h>

# define IMG_SIZE 48
# define ESCAPE 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define W 119
# define A 97 
# define S 115
# define D 100

# define INVALID_ARGS "Use : ./so_long <\"map\".ber.\n"
# define INVALID_FILE ""

typedef struct s_data_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}			t_data_img;

typedef struct s_img
{
	void	*wall;
	void 	*floor;
	void	*collectible;
	void	*perso;
	void	*exit;
	int		color;
}	t_img;

typedef struct s_err
{
	bool	borders;
	bool	row_len;
	int		item;
	int		ex;
	int		pos;
	int		character;
	int		inv_map;
}	t_err;

typedef struct s_map
{
	char	*map_str;
	char	**map;
	int		nb_col;
	int		nb_row;
	int		nb_item;
	int		pos_x;
	int		pos_y;
	void	*mlx_ptr;
	void	*mlx_win;
	int		img_size;
	int		nb_mov;
	t_img	sprite;
	t_data_img	img;
}	t_map;

void	exit_msg_err(char *err);
void	check_map(t_map *m, char *file);
void	get_map_str(t_map *m, char *file);
int		open_file(char *file);
void	free_matrix(char **tab);
void	check_layers(t_map *m, t_err *err);
void	check_line(int  i, char *line, t_map *m, t_err *err);
void	print_err_map(t_err *err);
void	flood_fill(int x, int y, t_map *m);
void	valid_map(t_map *m, t_err *err);
/* initalization struct map & error */
void	new_map(t_map *m);
void	new_err_map(t_map *m, t_err *err_map);
void	search_pos(t_map *m);
void	flood_fill(int x, int y, t_map *m);
/* render */
void	render(t_map *m);
void	set_sprite(t_map *m);
void	print_sprite(t_map *m, void *img, int x, int y);
void	put_floor(t_map *m);
void	render_frame(t_map *m);
void	put_others(t_map *m);
void	put_standard_sprite(t_map *m);
int		end_game(t_map *m);
void	move(t_map *m, int move_x, int move_y);
int	key_hook(int keycode, t_map *m);
int	update(t_map *m);

#endif
