/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:38 by dly               #+#    #+#             */
/*   Updated: 2022/12/17 18:49:22 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!is_digit(*str))
			return (2147483650);
	// check si return 0 ou INT_MAX + 1 exit on 0 
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

int	is_valid_dup(t_stack *a)
{
	elem	*check;
	elem	*current;

	current = a->first;
	while (current->next)
	{
		check = current->next;
		while (check->next)
		{
			if (current->num == check->num)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}
