/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:04 by dly               #+#    #+#             */
/*   Updated: 2022/11/30 19:34:58 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_nbr(int n, int *test)
{
	int		len;
	char	*str;	

	len = 0;
	str = ft_itoa(n);
	if (!str)
		return (0);
	len = ft_print_str(str, &len);
	test += len;
	if (str)
		free(str);
	return (len);
}
