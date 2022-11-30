/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:22:23 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 20:41:22 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_search_arg(va_list arg, char input, int *test)
{
	int	count;

	count = 0;
	if (input == 'c')
		count += ft_print_char(va_arg(arg, int), test);
	else if (input == 's')
		count += ft_print_str(va_arg(arg, char *), test);
	else if (input == 'p')
		count += ft_print_ptr(va_arg(arg, unsigned long long), test);
	else if (input == 'd' || input == 'i')
		count += ft_print_nbr(va_arg(arg, int), test);
	else if (input == 'u')
		count += ft_print_unsigned(va_arg(arg, unsigned int), test);
	else if (input == 'x' || input == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), input, test);
	else if (input == '%')
		count += ft_print_percent();
	return (count);
}

int	ft_read_txt(const char *input, int *count, int *i)
{
	int		len_txt;
	char	*next;

	len_txt = 0;
	next = ft_strchr(input, '%');
	if (next)
		len_txt = next - input;
	else
		len_txt = ft_strlen(input);
	write(1, input, len_txt);
	count += len_txt;
	i += len_txt;
	return (len_txt);
}

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	int		count;
	int		test;
	int		i;
	int		tmp;

	count = 0;
	i = 0;
	tmp = 0;
	va_start(arg, input);
	if (!input[i])
		return (0);
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += ft_search_arg(arg, input[i + 1], &test);
			i++;
		}
		else
		{
			tmp = ft_read_txt(input + i, &test, &i);
			i += tmp - 1;
			count += tmp;
		}
		i++;
	}
	va_end(arg);
	return (count);
}