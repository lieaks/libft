/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:34 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 18:55:45 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return ;
	(*stack)->first = NULL;
	(*stack)->last = NULL;
	(*stack)->length = 0;
}

t_stack *fill_stack(int ac, char **av)
{
	t_stack	*a;
	elem	*node;
	long	nb;
	int		i;

	init_stack(&a);
	if (!a)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		node = new_node((int)nb);
		if (nb > INT_MAX || nb < INT_MIN || !node)
		{
			free_stack(&a);
			free(node);
			exit(EXIT_FAILURE);
		}
		add_node_back(&a, &node);
		i++;
	}
	return (a);
}
