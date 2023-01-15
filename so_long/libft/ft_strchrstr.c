#include "libft.h"

int	ft_strchrstr(char *search, char **tab)
{
	int	x;
	int y;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (ft_strchr(search, tab[x][y]))
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}