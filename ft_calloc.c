/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:11:43 by dly               #+#    #+#             */
/*   Updated: 2022/11/12 18:08:33 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			n;

	n = nmemb * size;
	if (n > 2147483647)
	{
		write(2, "Overflow int", 12);
		exit(EXIT_FAILURE);
	}
	ptr = (unsigned char *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, n);
	return ((void *)ptr);
}
