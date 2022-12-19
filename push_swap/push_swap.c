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
		while ((*a)->first->index >= two_last)
			rotate(a);
		push(a, b);
	}
	if ((*a)->first->index > (*a)->first->next->index)
		rotate(a);
}

void	set_default_link(t_stack **a, t_stack **b)
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
	while (a_a)
	{
		a_a->link = a_a;
		a_a = a_a->next;
	}
}

void	get_link(t_stack **a, t_stack **b)
{
	elem	*a_a;
	elem	*b_b;

	a_a = (*a)->first;
	b_b = (*b)->first;
	// printf("--------------------------------------------------------\n");
	while (b_b)
	{
		a_a = (*a)->first;
		// printf("num : %d   index a : %ld     index b : %ld\n",b_b->num, a_a->index, b_b->link->index);
		while (a_a)
		{
			if(a_a->index > b_b->index && a_a->index < b_b->link->index)
			{
				// printf("index a : %ld     index b : %ld\n", a_a->index, b_b->index);
				b_b->link = a_a;
			}
			a_a = a_a->next;
		}
		b_b->cost = 0;
		// printf("index  : %d\n", b_b->link->num);
		b_b = b_b->next;
	}
}

int	search_pos_in_a(elem *a, elem *b, int half)
{
	int	pos;
	
	pos = 0;
	while (a != b && pos < half / 2)
	{
		pos++;
		a = a->next;
	}
	// printf("a : %ld  b : %ld \n", a->index, b->index);
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

void	get_cost(t_stack **a, t_stack **b)
{
	elem	*a_a;
	elem	*b_b;
	int		half;

	a_a = (*a)->first;
	b_b = (*b)->first;
	half = -1;
	while (b_b && half < (*b)->length / 2)
	{
		half++;
		// printf(" testtestseth      %p\n",b_b->link);
		b_b->cost += half + search_pos_in_a(a_a, b_b->link, (*b)->length);
		// printf("pos : %d\n", search_pos_in_a(a_a, b_b->link, (*b)->length));
		b_b = b_b->next;
		// printf(" next adress      %p\n",b_b->next);
		// printf(" length      %ld\n",(*b)->length);
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
/* Check which of the function : "rotate()" or "reverse_rotate()" is the costless
 * Default : reverse */
int	check_rotate_faster(elem *b, t_stack *stack)
{
	elem	*current;
	int		nb_move;

	nb_move = 0;
	current = stack->first;
	while (current)
	{
		if (current == b && nb_move <= stack->length / 2)
			return (1);
		nb_move++;
		current = current->next;
	}
	return (0);
}

void	sorting(t_stack **a, t_stack **b)
{
	elem	*lowest;

	lowest = get_lowest_cost((*b)->first);
	while ((*a)->first != lowest->link)
	{
		if (check_rotate_faster(lowest->link, *a))
			rotate(a);
		else
			reverse_rotate(a);
	}
	if ((*b)->length > 1)
	{
		while ((*b)->first != lowest)
		{
			if (check_rotate_faster(lowest, *b)) 
				rotate(b);
			else
				reverse_rotate(b);
		}
	}
	if ((*b)->length > 0)
		push(b, a); 
}
