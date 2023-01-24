/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:59:07 by dly               #+#    #+#             */
/*   Updated: 2023/01/24 18:25:05 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

# define INV_ARGS "Error\nUse : ./so_long <\"map\".ber>.\n"
# define INV_FILE "Error\nInvalid file type, please use .ber.\n"
# define INV_BORDERS "Error\nInvalid borders.\n"
# define INV_REC "Error\nMap must be rectangle!\n"
# define INV_COLLECTIBLE "Error\nNo collectible.\n"
# define INV_EXIT "Error\nInvalid exit.\n"
# define INV_POS "Error\nInvalid position.\n"
# define INV_CHAR "Error\nInvalid character.\n"
# define INV_MAP "Error\nInvalid path.\n"

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
	void	*floor;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*player_down1;
	void	*player_down2;
	void	*player_down3;
	void	*player_down4;
	void	*player_right1;
	void	*player_right2;
	void	*player_right3;
	void	*player_right4;
	void	*player_up1;
	void	*player_up2;
	void	*player_up3;
	void	*player_up4;
	void	*mob1;
	void	*mob2;
	void	*mob3;
	void	*mob4;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*exit4;
	void	*exit5;
	void	*exit6;
	void	*exit7;
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
	char		*map_str;
	char		**map;
	int			nb_col;
	int			nb_row;
	int			nb_item;
	int			nb_mob;
	int			pos_x;
	int			pos_y;
	void		*mlx_ptr;
	void		*mlx_win;
	int			img_size;
	int			nb_mov;
	int			on_exit;
	int			stance;
	t_img		sprite;
	t_data_img	img;
	t_err		err;
}	t_map;

/* error */
void	exit_msg_err(t_map *m, char *err);
void	print_err_map(t_map *m);
/* file */
int		open_file(t_map *m, char *file);
/* map / parsing */
void	get_map_str(t_map *m, char *file);
void	check_map(t_map *m, char *file);
void	check_layers(t_map *m);
void	check_line(int i, char *line, t_map *m);
/* render */
void	render(t_map *m);
/* flood fill */
void	flood_fill(int x, int y, t_map *m);
/* initalization struct map & error */
void	new_map(t_map *m);
void	new_err_map(t_map *m);
void	new_sprite(t_map *m);
void	search_pos(t_map *m);
/* sprites */
void	set_sprite(t_map *m);
void	print_sprite(t_map *m, void *img, int x, int y);
void	put_standard_sprite(t_map *m);
/* move */
void	move(t_map *m, int move_x, int move_y, int stance);
int		key_hook(int keycode, t_map *m);
void	print_nb_mov(t_map *m);
/* load_img */
void	set_coin(t_map *m);
void	set_player(t_map *m);
void	set_player_down(t_map *m);
void	set_player_right(t_map *m);
void	set_player_up(t_map *m);
void	set_exit(t_map *m);
void	set_mob(t_map *m);
/* free */
void	free_img_player(t_map *m);
void	free_img_exit(t_map *m);
void	free_img(t_map *m);
void	free_matrix(char **tab);
int		end_game(t_map *m);
/* animation_player.c */
int		update(t_map *m);
void	anim_player_down(t_map *m, int i, int x, int y);
void	anim_player_right(t_map *m, int i, int x, int y);
void	anim_player_up(t_map *m, int i, int x, int y);
void	anim_mob(t_map *m, int i, int x, int y);

#endif
