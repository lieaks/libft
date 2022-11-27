/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:26:21 by dly               #+#    #+#             */
/*   Updated: 2022/11/27 18:30:16 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*cdest;
	const char	*csrc;

	if (!dest)
		return (NULL);
	cdest = (char *)dest;
	csrc = (const char *)src;
	while (n > 0)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
		n--;
	}
	return (dest);
}
