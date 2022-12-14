/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:35:12 by dly               #+#    #+#             */
/*   Updated: 2022/12/14 17:36:01 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	node;
	long	nb;
	int		i;

	while (ac > 1)
	{
		nb = 0;
		nb = ft_atoi(av[ac - 1]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit(EXIT_FAILURE);
		if (!nb)
			return (NULL);
		node = ft_lstnew(nb);
		if (!a)
			return (NULL);
		push_front(a, node);
		ac--;
	}
	if (!is_valid(a))
	{
		
	}
	return (a);
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (1);
	while (i < ac)
	{
		if (!is_valid(av[i]))
			return (1);
	}
	push_swap(av);
	return (0);
}
