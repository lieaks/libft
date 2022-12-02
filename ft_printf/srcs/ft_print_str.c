/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:30 by dly               #+#    #+#             */
/*   Updated: 2022/12/02 12:42:22 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int *arg_count)
{
	if (!str)
	{
		*arg_count += 6;
		write(1, "(null)", 6);
		return ;
	}
	*arg_count += write(1, str, ft_strlen(str));
}
