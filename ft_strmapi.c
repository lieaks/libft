/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:06 by dly               #+#    #+#             */
/*   Updated: 2022/11/15 16:14:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = (*f)(i, ptr[i]);
		i++;
	}
	return (ptr);
}
