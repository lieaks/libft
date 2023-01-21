
#include "../include/so_long.h"

void	check_layers(t_map *m, t_err *err)
{
	int	i;
	
	i = 0;
	while (m->map[i])
	{
		check_line(i, m->map[i], m, err);
		i++;
	}
}

void	check_line(int i, char *line, t_map *m, t_err *err)
{
	int	idx;

	idx = 0;
	if (m->nb_col == 0)
		m->nb_col = ft_strlen(line);
	if ((int)ft_strlen(line) != m->nb_col) 
		err->row_len = 1;
	if ((i == 0 || i == m->nb_row - 1) && ft_count_char(line, '1') != m->nb_col)
		err->borders = 1;
	if (line[0] != '1' || line[m->nb_col - 1] != '1')
		err->borders = 1;
	err->item += ft_count_char(line, 'C');
	m->nb_item = err->item;
	err->ex += ft_count_char(line, 'E');
	err->pos += ft_count_char(line, 'P');
	while (line[idx])
	{
		if (!ft_strchr("01CEP", line[idx]))
			err->character = 1;
		idx++;
	}
}