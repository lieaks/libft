#include "libft.h"

int	ft_count_char(char *str, char c)
{
	int	res;
	int	i;
	
	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

