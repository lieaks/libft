/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:11:43 by dly               #+#    #+#             */
/*   Updated: 2022/11/24 19:40:38 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb && ((size * nmemb) / size ) != nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
int main()
{
	size_t	a = LONG_MAX + 1;
	size_t	b = 1;
	size_t	*ptr = ft_calloc(a,b);
	size_t	*real = calloc(a,b);
	printf("%p\n", ptr);
	printf("%p\n", real);
	printf("%d\n", LONG_MAX);
	free(ptr);
	free(real);
	return 0;
}*/
