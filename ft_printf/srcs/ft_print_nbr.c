/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:04 by dly               #+#    #+#             */
/*   Updated: 2022/12/02 12:42:19 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int n, int *arg_count)
{
	char	*str;
	int		str_count;

	str_count = 0;
	str = ft_itoa(n);
	if (!str)
		return ;
	ft_print_str(str, &str_count);
	if (str)
		free(str);
	*arg_count += str_count;
}
