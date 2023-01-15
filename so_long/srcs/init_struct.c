#include "../include/so_long.h"

void	new_map(t_map *m)
{
	m->nb_col = 0;
	m->nb_row = 0;
	m->nb_item = 0;
	m->map_str = NULL;
	m->map = NULL;
}

void	new_err_map(t_map *m, t_err *err_map)
{
	err_map->borders = 0;
	err_map->item = 0;
	err_map->pos = 0;
	err_map->ex = 0;
	err_map->character = 0;
	err_map->inv_map = 0;
}

void	search_pos(t_map *m)
{
	int	x;
	int y;

	x = 0;
	while (m->map[x])
	{
		y = 0;
		while (m->map[x][y])
		{
			if (m->map[x][y] == 'P')
			{
				m->pos_x = x;
				m->pos_y = y;
			}
			y++;
		}
		x++;
	}
}
