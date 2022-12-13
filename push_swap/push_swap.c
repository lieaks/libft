/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:35:12 by dly               #+#    #+#             */
/*   Updated: 2022/12/13 19:14:28 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list init_stack(int ac, char **av)
{
	t_list	a;
	t_list	node;
	int		nb;
	int		i;

	while (ac > 1)
	{
		nb = 0;
		nb = ft_atoi(av[ac - 1]);
		if (!nb)
			return (NULL);
		node = ft_lstnew(nb);
		if (!a)
			return (NULL);
		push_front(a, node);
		ac--;
	}
	return (a);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	push_swap(av);
	return (0);
}
