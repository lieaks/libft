#include "ft_prinf.h"


const char	*ft_read_text(const char *input, int *count)
{
	int		len_text;
	char	*next;
// % sans rien apres ou arg non valide a check
	next = ft_strchr(input, '%'); 
	if (next)
		len_text = next - input;
	else
		len_text = ft_strlen(next);
	write(1, input, len_text);
	count += len_text;
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
			input = ft_read_text(input, &sum);
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
