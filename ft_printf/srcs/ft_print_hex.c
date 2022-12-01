/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:10:51 by dly               #+#    #+#             */
/*   Updated: 2022/12/01 20:19:04 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int n, char c, t_sc *sc)
{
	sc->count += ft_len_nb((unsigned long long)n, "0123456789abcdef");
	if (c == 'x')
		ft_itoa_base((unsigned long long)n, "0123456789abcdef");
	else if (c == 'X')
		ft_itoa_base((unsigned long long)n, "0123456789ABCDEF");
}
