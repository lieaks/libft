/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:47:42 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 17:03:46 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Searching the elem that have the smaller operations and return that elem */
t_elem	*get_lowest_cost(t_elem *b)
{
	t_elem	*lowest;

	lowest = b;
	while (b)
	{
		if (b->cost < lowest->cost)
			lowest = b;
		b = b->next;
	}
	return (lowest);
}

void	use_rr_rrr(t_stack **a, t_stack **b)
{
	t_elem	*lowest;

	lowest = get_lowest_cost((*b)->first);
	while (((*a)->first != lowest->link && (*b)->first != lowest)
		&& (way(lowest->link, *a) == way(lowest, *b)))
	{
		if (way(lowest->link, *a) && way(lowest, *b))
			rr(a, b);
		else if (!way(lowest->link, *a) && !way(lowest, *b))
			rrr(a, b);
	}
}

void	sorting(t_stack **a, t_stack **b)
{
	t_elem	*lowest;

	lowest = get_lowest_cost((*b)->first);
	while ((*a)->first != lowest->link)
	{
		if (way(lowest->link, *a))
			rotate('a', a);
		else
			reverse_rotate('a', a);
	}
	if ((*b)->length > 1)
	{
		while ((*b)->first != lowest)
		{
			if (way(lowest, *b))
				rotate('b', b);
			else
				reverse_rotate('b', b);
		}
	}
	if ((*b)->length > 0)
		push('a', b, a);
}
