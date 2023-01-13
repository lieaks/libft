/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:52:35 by dly               #+#    #+#             */
/*   Updated: 2023/01/13 15:33:20 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *str1, char *str2)
{
	char	*res;
	size_t	i;
	size_t	len;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	len = ft_strlen(str1) + ft_strlen(str2);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (*str1)
		res[i++] = *str1++;
	while (*str2)
		res[i++] = *str2++;
	return (res);
}
