
#include "so_long.h"

char	**parse(char *av)
{
	int		fd;
	int		readed;
	char	*line;	
	char	buf[42];
	char	**map;

	fd = open(av[1], O_RDONLY);
	if (!fd)
		exit_msg_err("File not found");
	readed = 1; 
	while (readed)
	{
		readed = read(fd, buf, 42);
		if (readed < 0)
			error;
		line = ft_join();
		if (!map)
			error;
	}
	map = ft_split(line, '\n');
	if (!map)
		error;
	return (map);
}

int	check(char **map)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != 1)
			return ();
		j++;
	}
	len = j;
	
	return (1);
}

int	main(int ac, char **av)
{
	t_map	m;

	if (ac != 2)
		return (1);
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
