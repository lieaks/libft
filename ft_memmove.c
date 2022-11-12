/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:14:06 by dly               #+#    #+#             */
/*   Updated: 2022/11/12 16:44:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	cdest = (char *)dest;
	csrc = (const char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			cdest[n] = csrc[n];
		}
	}
	else
		ft_memcpy(cdest, csrc, n);
	return (dest);
}
