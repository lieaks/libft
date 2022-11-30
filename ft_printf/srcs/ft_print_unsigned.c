/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:45 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 20:49:47 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_write_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		ft_write_unsigned(n / 10);
		ft_write_unsigned(n % 10);
	}
	else
		write(1, &n, 1);
}

int	ft_print_unsigned(unsigned int n, int *test)
{
	int	count;

	count = 0;
	ft_write_unsigned(n);
	if (n == 0)
		count++;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	test += count;
	return (count);
}
