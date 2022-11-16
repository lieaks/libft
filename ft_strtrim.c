/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:14:54 by dly               #+#    #+#             */
/*   Updated: 2022/11/15 20:49:26 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
	{
		if (!ft_is_in_set(s1[len], set))
			i++;
		len++;
	}
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	while (len >= 0)
	{
		if (!ft_is_in_set(s1[len], set))
		{
			ptr[i] = s1[len];
			i--;
		}
		len--;
	}
	return (ptr);
}
