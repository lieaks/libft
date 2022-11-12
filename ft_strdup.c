/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:44:17 by dly               #+#    #+#             */
/*   Updated: 2022/11/12 18:36:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s);
	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
	{
		errno = 12;
		return (NULL);
	}
	ft_memmove(ptr, s, n);
	ptr[n] = '\0';
	return (ptr);
}
