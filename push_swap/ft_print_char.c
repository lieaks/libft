/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:10:40 by dly               #+#    #+#             */
/*   Updated: 2022/12/20 15:34:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_char(int c, t_sc *sc)
{
	sc->count += 1;
	write(1, &c, 1);
}
void	ft_print_nbr(int n, t_sc *sc)
{
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return ;
	ft_print_str(str, sc);
	if (str)
		free(str);
}

void	ft_print_str(char *str, t_sc *sc)
{
	if (!str)
	{
		sc->count += 6;
		write(1, "(null)", 6);
		return ;
	}
	sc->count += write(1, str, ft_strlen(str));
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
