/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:30 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 15:11:31 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_str(char *str, int *test)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)" 6));
	while (str[i])
		i += write(1, str + i, 1);
	test += len;
	return (i);
}
