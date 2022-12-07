/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:22 by dly               #+#    #+#             */
/*   Updated: 2022/12/02 17:20:36 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
