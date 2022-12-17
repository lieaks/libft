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
	parsing(a);
}
int	lowest(t_stack *a)
{
	elem	*e;
	int		num;

	num = INT_MAX;
	e = a->first;
	while (e)
	{
		if (e->num <= num && !(e->index))
			num = e->num;
		e = e->next;
	}
	return (num);
}

void	parsing(t_stack **a)
{
	elem 	*e;
	long	rank;

	rank = 1;
	e = (*a)->first;
	while(rank <= (*a)->length)
	{	
		if (e->num == lowest(*a))
			e->index = rank++;
		e = e->next;
		if (!e)
			e = (*a)->first;
	}
}

void	get_two_last(t_stack **a, t_stack **b)
{
	long	two_last;

	two_last = (*a)->length - 1;
	while ((*a)->length > 2)
	{
		if ((*a)->first->index >= two_last)
			rotate(a);
		push(a, b);
	}
	if ((*a)->first->index > (*a)->first->next->index)
		rotate(a);
}

void	get_link(t_stack **a, t_stack **b)
{
	elem	*a_a;
	elem	*b_b;	

	a_a = (*a)->first;
	b_b = (*b)->first;
	while (b_b)
	{
		b_b->link = a_a;
		b_b = b_b->next;
	}
	while (b_b)
	{
		while (a_a)
		{
			if(a_a->index > b_b->index && a_a->index < b_b->link->index)
				b_b->link = b_b;
			a_a = a_a->next;
		}
		b_b = b_b->next;
	}
}