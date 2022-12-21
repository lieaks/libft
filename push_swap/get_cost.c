/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:22 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 16:46:38 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_pos_in_a(t_elem *a, t_elem *b, int half)
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
	if (half % 2)
		pos++;
	while (a && a != b)
	{
		pos--;
		a = a->next;
	}
	return (pos);
}

/* assign the real cost (moving in a then in b) to each element */
void	get_cost(t_stack **a, t_stack **b)
{
	t_elem	*a_a;
	t_elem	*b_b;
	int		half;

	half = -1;
	a_a = (*a)->first;
	b_b = (*b)->first;
	while (b_b && half < (*b)->length / 2)
	{
		half++;
		b_b->cost += half + search_pos_in_a(a_a, b_b->link, (*b)->length);
		b_b = b_b->next;
	}
	if ((*b)->length % 2)
		half++;
	while (b_b)
	{
		half--;
		b_b->cost += half + search_pos_in_a(a_a, b_b->link, (*b)->length);
		b_b = b_b->next;
	}
}
