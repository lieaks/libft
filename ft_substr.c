/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:37:37 by dly               #+#    #+#             */
/*   Updated: 2022/11/17 13:24:35 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	real_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	real_len = 0;
	if (start < s_len)
		real_len = s_len - start;
	if (real_len > len)
		real_len = len;
	ptr = (char *)malloc(real_len + 1);
	if (!ptr)
		return (NULL);
	i = start;
	j = 0;
	while (i < s_len && j < real_len)
		ptr[j++] = s[i++];
	ptr[j] = '\0';
	return (ptr);
}
