/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:14:45 by dly               #+#    #+#             */
/*   Updated: 2022/12/02 12:42:23 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_nb(unsigned long long ptr, char *base)
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
		ptr /= ft_strlen(base);
	}
	return (count);
}

int	ft_itoa_base(unsigned long long nb, char *base)
{
	int			len;
	char		*result;

	len = ft_len_nb(nb, base);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	len--;
	if (nb == 0)
		result[0] = base[0];
	while (nb > 0)
	{
		result[len--] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	write(1, result, ft_strlen(result));
	free(result);
	return (1);
}
