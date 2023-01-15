
#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_map	m;

	if (ac != 2)
		exit_msg_err("Invalid nb of arguments.\n");
	check_map(&m, av[1]);	
	init_game(m);
	return (0);
}
