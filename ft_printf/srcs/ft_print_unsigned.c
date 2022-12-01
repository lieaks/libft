/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:45 by dly               #+#    #+#             */
/*   Updated: 2022/12/01 20:02:00 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_unsigned(unsigned int n, t_sc *sc)
{
	sc->count = ft_len_nb((unsigned long long)n, "0123456789");
	ft_itoa_base((unsigned long long)n, "0123456789");
}
