/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:22:23 by dly               #+#    #+#             */
/*   Updated: 2022/12/20 15:18:52 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_charset(char format, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (format == charset[i])
			return (1);
		i++;
	}
	return (0);
}

const char	*is_format(const char *format, t_sc *sc)
{
	int	i;

	i = 1;
	if (!is_in_charset(format[i], " cspdiuxX%"))
	{
		sc->count += write(1, format, i + 1);
		sc->error = 1;
		return (format + i);
	}
	while (format[i] && format[i] == ' ')
	{
		i++;
		if (!is_in_charset(format[i], " cspdiuxX%"))
		{
			sc->count += write(1, format, 1);
			sc->count += write(1, " ", 1);
			sc->count += write(1, format + i, 1);
			sc->error = 1;
			break ;
		}
	}
	return (format + i);
}

const char	*ft_search_arg(va_list arg, const char *format, t_sc *sc)
{
	if (*format == '%' && *(format + 1) == 0)
	{
		if (sc->error == 0)
			sc->count = -1;
		if (sc->error == 1)
			sc->count += write(1, format, 1);
		return (format + 1);
	}
	else
		format = is_format(format, sc);
	if (*format == 'c')
		ft_print_char(va_arg(arg, int), sc);
	else if (*format == 's')
		ft_print_str(va_arg(arg, char *), sc);
	else if (*format == 'p')
		ft_print_ptr(va_arg(arg, unsigned long long), sc);
	else if (*format == 'd' || *format == 'i')
		ft_print_nbr(va_arg(arg, int), sc);
	else if (*format == 'u')
		ft_print_unsigned(va_arg(arg, unsigned int), sc);
	else if (*format == 'x' || *format == 'X')
		ft_print_hex(va_arg(arg, unsigned int), *format, sc);
	else if (*format == '%')
		ft_print_char('%', sc);
	return (format + 1);
}

const char	*ft_read_txt(const char *format, t_sc *sc)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
		sc->len = next - format;
	else
		sc->len = ft_strlen(format);
	sc->count += sc->len;
	write(1, format, sc->len);
	while (*format && *format != '%')
		format++;
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	t_sc	sc;

	va_start(arg, format);
	sc.count = 0;
	sc.len = 0;
	sc.error = 0;
	if (!*format)
		return (0);
	while (*format)
	{
		if (*format == '%')
			format = ft_search_arg(arg, format, &sc);
		else
			format = ft_read_txt(format, &sc);
	}
	va_end(arg);
	return (sc.count);
}
