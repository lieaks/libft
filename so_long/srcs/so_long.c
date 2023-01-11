
#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	m;

	if (ac != 2)
		return (1);
	m.file = open(av[1], O_RDONLY);
	if (!m.file)
		exit_msg_err("File not found");
	init_map(m.map);
	while (1)
	(
		new_node(get_next_line(m.file, 0));
		m.map->line == get_next_line(m.file, 0);
		if (m.map->line == NULL)
			break ;

		
	)
	return (0)
}
