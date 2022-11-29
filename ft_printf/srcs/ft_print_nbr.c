#include "../include/ft_printf.h"

int	ft_print_nbr(int n, int *test) 
{
	int		len;
	char	*str;	

	len = 0;
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_print_str(str);
	test += len;
	if (str)
		free(str);
	return (len);
}
