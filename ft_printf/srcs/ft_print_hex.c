/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:10:51 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 15:16:06 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_hex(unsigned int n, char input, int *test)
{
	test += ft_len_hex_ullong((unsigned long long)n);
	if (input == 'x')
		ft_write_hex((unsigned long long)n, 'a');
	else if (input == 'X')
		ft_write_hex((unsigned long long)n, 'A');
	return (ft_len_hex_ullong((unsigned long long)n));
}
