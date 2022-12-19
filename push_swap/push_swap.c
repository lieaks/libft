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
		printf("Error\n");
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
		{
			rotate('a', a);
			(*a)->ope++;
		}
		push('b', a, b);
		(*a)->ope++;
	}
	if ((*a)->first->index > (*a)->first->next->index)
	{
		rotate('a', a);
		(*a)->ope++;
	}
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
	while (b_b)
	{
		a_a = (*a)->first;
		while (a_a)
		{
			if(a_a->index > b_b->index && a_a->index < b_b->link->index)
				b_b->link = a_a;
			a_a = a_a->next;
		}
		b_b->cost = 0;
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
			rotate('a', a);
		else
			reverse_rotate('a', a);
		(*a)->ope++;
	}
	if ((*b)->length > 1)
	{
		while ((*b)->first != lowest)
		{
			if (check_rotate_faster(lowest, *b)) 
				rotate('b', b);
			else
				reverse_rotate('b', b);
			(*a)->ope++;
		}
	}
	if ((*b)->length > 0)
	{
		push('a', b, a); 
		(*a)->ope++;
	}
}

elem	*search(int rank, elem *stack)
{
	elem	*pos;

	pos = stack;
	while (pos)
	{
		if (rank == pos->index)
			return (pos);
		pos = pos->next;
	}
	return (NULL);
}

void	last_rotate(t_stack **a)
{
	elem	*one;

	one = search(1, (*a)->first);
	while ((*a)->first != one)
	{
		if (!check_rotate_faster(one, *a))
			reverse_rotate('a', a);	
		else
			rotate('a', a);
		(*a)->ope++;
	}
}
