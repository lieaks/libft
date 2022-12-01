/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:11:30 by dly               #+#    #+#             */
/*   Updated: 2022/12/01 20:23:13 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_str(char *str, t_sc *sc)
{
	if (!str)
	{
		sc->count += 6;
		write(1, "(null)", 6);
		return ;
	}
	sc->len = ft_strlen(str);
	sc->count += write(1, str, sc->len);
}
