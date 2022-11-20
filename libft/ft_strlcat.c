/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:46:01 by dly               #+#    #+#             */
/*   Updated: 2022/11/19 17:22:19 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (!size)
		return (len);
	i = ft_strlen(dst);
	if (size < i)
		len += size;
	else
		len += i;
	while (i < (size - 1) && *src && size > 0)
	{
		dst[i] = *src;
		src++;
		if (i < (size - 1))
			dst[i + 1] = '\0';
		i++;
	}
	return (len);
}
