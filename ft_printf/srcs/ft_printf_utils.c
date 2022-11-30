/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:14:45 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 15:15:23 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_len_hex_ullong(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count++;
		return (count);
	}
	while (ptr > 0)
	{
		count++;
		ptr /= 16;
	}
	return (count);
}

void	ft_write_hex(unsigned long long ptr, char a_or_A)
{
	if (ptr >= 16)
	{
		ft_write_str(ptr / 16);
		ft_write_str(ptr % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr + a_or_A), 1);
	}
}