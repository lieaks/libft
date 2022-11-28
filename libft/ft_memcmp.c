/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:23:13 by dly               #+#    #+#             */
/*   Updated: 2022/11/28 14:01:37 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;
	size_t			i;

	if (n == 0)
		return (0);
	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	i = 0;
	while (first[i] == second[i] && i < n - 1)
	{
		i++;
	}
	return (first[i] - second[i]);
}
