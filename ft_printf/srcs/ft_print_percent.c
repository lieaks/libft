#include "../include/ft_printf.h"

int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}
