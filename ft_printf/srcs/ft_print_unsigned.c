/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:45 by dly               #+#    #+#             */
/*   Updated: 2022/12/02 12:42:22 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int n, int *arg_count)
{
	*arg_count += ft_len_nb((unsigned long long)n, "0123456789");
	ft_itoa_base((unsigned long long)n, "0123456789");
}
