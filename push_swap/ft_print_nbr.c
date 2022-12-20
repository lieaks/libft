/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:04 by dly               #+#    #+#             */
/*   Updated: 2022/12/20 15:16:09 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_unsigned(unsigned int n, t_sc *sc)
{
	sc->count += ft_len_nb((unsigned long long)n, "0123456789");
	ft_itoa_base((unsigned long long)n, "0123456789");
}

void	ft_print_ptr(unsigned long long ptr, t_sc *sc)
{
	if (!ptr)
		sc->count += write(1, "(nil)", 5);
	else
	{
		sc->count += ft_len_nb(ptr, "0123456789abcdef");
		sc->count += write(1, "0x", 2);
		ft_itoa_base(ptr, "0123456789abcdef");
	}
}

void	ft_print_hex(unsigned int n, char c, t_sc *sc)
{
	sc->count += ft_len_nb((unsigned long long)n, "0123456789abcdef");
	if (c == 'x')
		ft_itoa_base((unsigned long long)n, "0123456789abcdef");
	else if (c == 'X')
		ft_itoa_base((unsigned long long)n, "0123456789ABCDEF");
}