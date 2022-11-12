/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:45:12 by dly               #+#    #+#             */
/*   Updated: 2022/11/09 15:35:58 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int			i;
	const char	*dest;

	i = 0;
	dest = s;
	while (n > 0)
	{
		if (dest[i] == c)
			return ((void *)dest);
		n--;
	}
	return (NULL);
}
