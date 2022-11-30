/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:22 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 15:13:16 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_ptr(unsigned long long ptr, int *test)
{
	int	len;

	len = ft_ptr_len(ptr);
	len += write(1, "0x", 2);
	ft_write_hex(ptr, 'a');
	test += len;
	return (len);
}
