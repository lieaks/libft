/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:22 by dly               #+#    #+#             */
/*   Updated: 2022/12/29 17:39:39 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_rr(t_elem *a, t_elem *b, int half)
{
	int	pos;

	pos = 0;
	while (a != b && pos < half / 2)
	{
		pos++;
		a = a->next;
	}
	if (a == b)
		return (pos);
	return (0);
}

int	search_rrr(t_elem *a, t_elem *b, int half)
{
	int	pos;

	pos = 1;
	while (a != b && pos < half / 2)
	{
		pos++;
		a = a->prev;
	}
	if (a == b)
		return (pos);
	return (0);
}

void	get_first_cost(t_stack **a, t_stack **b)
{
	t_elem	*b_b;
	int		half;

	half = -1;
	b_b = (*b)->first;
	while (b_b && half < (*b)->length / 2)
	{
		half++;
		b_b->cost = search_rrr((*a)->last, b_b->link, (*a)->length);
		if (half >= search_rr((*a)->first, b_b->link, (*a)->length))
			b_b->cost += half;
		else
			b_b->cost += search_rr((*a)->first, b_b->link, (*a)->length);
		b_b = b_b->next;
	}	
}

void	get_last_cost(t_stack **a, t_stack **b)
{
	t_elem	*b_b;
	int		half;

	half = 0;
	b_b = (*b)->last;
	while (b_b && half < (*b)->length / 2)
	{
		half++;
		b_b->cost = search_rr((*a)->first, b_b->link, (*a)->length);
		if (half >= search_rrr((*a)->last, b_b->link, (*a)->length))
			b_b->cost += half;
		else
			b_b->cost += search_rrr((*a)->last, b_b->link, (*a)->length);
		b_b = b_b->prev;
	}
}

/* assign the real cost (moving in a then in b) to each element */
void	get_cost(t_stack **a, t_stack **b)
{
	get_first_cost(a, b);
	get_last_cost(a, b);
}
