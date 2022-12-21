/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_a_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:34 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 16:45:03 by dly              ###   ########.fr       */
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

int	is_valid_dup(t_stack *a)
{
	t_elem	*check;
	t_elem	*current;

	current = a->first;
	while (current->next)
	{
		check = current->next;
		while (check)
		{
			if (current->num == check->num)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

void	ready_a_b(t_stack **a, t_stack **b)
{
	init_stack(b);
	if (!is_valid_dup(*a) || !*b)
	{
		free_stack(a);
		if (b)
			free_stack(b);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	assign_rank(a);
	get_two_last(a, b);
	set_default_link(a, b);
}
