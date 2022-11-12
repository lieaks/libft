/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:01 by dly               #+#    #+#             */
/*   Updated: 2022/11/12 16:49:02 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = ft_strlen(dst);
	len = ft_strlen(src);
	if (size < i)
		len += size;
	else
		len += i;
	while (i < (size - 1) && *src && size > 0)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = 0;
	return (len);
}
