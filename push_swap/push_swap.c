/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:35:12 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 20:24:52y dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ready_a_b(t_stack **a, t_stack **b)
{
	init_stack(b);
	if (!is_valid_dup(*a) || !*b)
	{
		free_stack(a);
		if (b)
			free_stack(b);
		exit(EXIT_FAILURE);
	}
}

void	parsing(t_stack **a)
{
	t_stack	*current;
	int		rank;

	rank = 1;
	current = *a;
	current->min = current->first->num;
	printf("%d\n",current->length);
	while(rank <= current->length)
	{
		current->first = (*a)->first;
		if (current->first->num < current->min && !current->first->index)
			current->min = current->first->num; 
		current->first = current->first->next;
		if (current->first->next == NULL)
		{
			current->first = (*a)->first;
			while (current->first->next)
			{
				if (current->first->num == current->min)
					current->first->index = rank++;
			}
		}
	}
}