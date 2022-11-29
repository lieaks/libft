#include "../include/ft_printf.h"

static void	ft_write_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_write_str(n / 10);
		ft_write_str(n % 10);
	}
	else
		ft_putchar_fd(n, 1);
}

int	ft_print_unsigned(unsigned int n, int *test)
{
	int	count;

	count = 0;
	ft_write_unsigned(n);
	if (n == 0)	
		count++;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	test += count;
	return (count);
}

