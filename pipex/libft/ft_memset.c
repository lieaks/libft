/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:14:03 by dly               #+#    #+#             */
/*   Updated: 2023/01/03 17:28:17 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = s;
	while (n > 0)
	{
		*tmp = c;
		tmp++;
		n--;
	}
	return (s);
}
