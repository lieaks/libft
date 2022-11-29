#include "../include/ft_printf.h"

int	ft_print_str(char *str, int *test)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)" 6));
	while (str[i])
		i += write(1, str + i, 1);
	test += len;
	return (i);
}
