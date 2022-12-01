/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:22:23 by dly               #+#    #+#             */
/*   Updated: 2022/12/01 20:32:41 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

const char	*ft_search_arg(va_list arg, const char *format, t_sc *sc)
{
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
		ft_print_percent(sc);
	format++;
	return (format);
}

const char	*ft_read_txt(const char *format, t_sc *sc)
{
	char	*next;

	next = ft_strchr(format, '%');
	if (next)
		sc->len = next - format;
	else
		sc->len = ft_strlen(format);
	write(1, format, sc->len);
	sc->count += sc->len;
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
	if (!*format)
		return (0);
	while (*format)
	{
		if (*format == '%')
			format = ft_search_arg(arg, format + 1, &sc);
		else
			format = ft_read_txt(format, &sc);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.count);
		}
	}
	va_end(arg);
	return (sc.count);
}
