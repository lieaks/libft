/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:55:28 by dly               #+#    #+#             */
/*   Updated: 2022/11/27 17:45:56 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	if (s1)
	{
		while (s1[j])
			ptr[i++] = s1[j++];
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			ptr[i++] = s2[j++];
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (unsigned char)c)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!size || !nmemb)
		return (ft_calloc(1, 1));
	if (((size * nmemb) / size) != nmemb)
		return (NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	tmp = s;
	while (n > 0)
	{
		*tmp = c;
		tmp++;
		n--;
	}
	return (s);
}
