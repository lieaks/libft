/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:24:13 by dly               #+#    #+#             */
/*   Updated: 2022/11/18 12:51:20 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	b;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		b = 0;
		while (big[i + b] == little[b] && i + b < len)
		{
			b++;
			if (b == little_len)
				return ((char *)(big + i));
		}
		i++;
	}
	return ((NULL));
}
