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


/* Searching the elem that have the smaller operations and return that elem */
elem	*get_lowest_cost(elem *b)
{
	elem	*lowest;

	lowest = b;
	while (b)
	{
		if (b->cost < lowest->cost)
			lowest = b;
		b = b->next;
	}
	return (lowest);
}


void	sorting(t_stack **a, t_stack **b)
{
	elem	*lowest;

	lowest = get_lowest_cost((*b)->first);
	while ((*a)->first != lowest->link)
	{
		if (check_rotate_faster(lowest->link, *a))
			rotate('a', a);
		else
			reverse_rotate('a', a);
	}
	if ((*b)->length > 1)
	{
		while ((*b)->first != lowest)
		{
			if (check_rotate_faster(lowest, *b)) 
				rotate('b', b);
			else
				reverse_rotate('b', b);
		}
	}
	if ((*b)->length > 0)
		push('a', b, a); 
}

