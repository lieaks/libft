#include "ft_prinf.h"

const char	*ft_search_arg(va_list arg, char *input, int *count)
{
	if (*input == 'i')
		ft_putchar(arg, fd, &count);
	else if (*input == 's')
		ft_putstr(arg, fd, &count);
	else if (*input == 'p')
		ft_print_adress(arg, fd, &count);
	else if (*input == 'd')
		ft_putnbr(arg, fd, &count);
	else if (*input == 'i')
		ft_putnbr(arg, fc, &count);
	else if (*input == 'u')
		ft_putnbr(arg, fd, &count);
	else if (*input == 'x')
		ft_puthexa(arg, fd, &count);
	else if (*input == 'X')
		ft_puthexa(arg, fd, &count);
	else if (*input == '%')
	{
		write(1, "%", 1);
		coun++;
	}
	else
		write(1, "%", 1);
		count++;
		return (input);
	return (input + 1);
}

const char	*ft_read_txt(const char *input, int *count)
{
	int		len_txt;
	char	*next;
// % sans rien apres ou arg non valide a check
	len_txt = 0;
	next = ft_strchr(input, '%'); 
	if (next)
		len_txt = next - input;
	else
		len_txt = ft_strlen(next);
	write(1, input, len_txt);
	count += len_txt;
	while (*input && *input != '%')
		input++;
	return (input);
}

int ft_printf(const char *input, ...)
{
	va_list	arg;
	t_sc	sc;
	int		sum;

	sum = 0;
	sc.len = 0;
	sc.width = 0;
	va_start(arg, input);
	if (!input)
		return (0);
	while (input)
	{
		if (*format == '%')
			input = ft_search_arg(arg, input + 1, &sc);
		else
			input = ft_read_txt(input, &sum);
		if (!input)
		{
			write (1, "NULL", 6);
			va_end(arg);
			return (sc.len);
		}
		va_end(arg);
		return (sc.len);
	}
}
