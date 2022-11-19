/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:25 by dly               #+#    #+#             */
/*   Updated: 2022/11/18 21:27:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_itoa(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	nb;
	size_t	i;

	nb = (long)n;
	i = ft_size_itoa(nb);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	i--;
	if (nb == 0)
		ptr[0] = '0';
	else if (nb < 0)
	{
		ptr[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		ptr[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (ptr);
}
