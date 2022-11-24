/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:44:17 by dly               #+#    #+#             */
/*   Updated: 2022/11/17 13:17:58 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, s, n);
	ptr[n] = '\0';
	return (ptr);
}
