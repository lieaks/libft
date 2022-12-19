/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:52 by dly               #+#    #+#             */
/*   Updated: 2022/12/19 18:31:56 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(char c, t_stack **stack)
{
	elem	*tmp;
	elem	*last;
	elem	*first;

	if ((*stack)->first == NULL)
		return ;
	tmp = (*stack)->first;
	first = (*stack)->first->next;
	last = (*stack)->last;
	first->prev = NULL;
	tmp->prev = last;
	tmp->next = NULL;
	last->next = tmp;
	(*stack)->first = first;
	(*stack)->last = tmp;
	if (c == 'a')
		printf("ra\n");
	if (c == 'b')
		printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate('a', a);
	rotate('b', b);
}

void	reverse_rotate(char c, t_stack **stack)
{
	elem	*tmp;
	elem	*last;
	elem	*first;

	if ((*stack)->first == NULL)
		return ;
	tmp = (*stack)->last;
	first = (*stack)->first;
	last = (*stack)->last->prev;
	first->prev = tmp; 
	tmp->prev = NULL;
	tmp->next = first;
	last->next = NULL; 
	(*stack)->first = tmp;
	(*stack)->last = last;
	if (c == 'a')
		printf("rra\n");
	if (c == 'b')
		printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate('a', a);
	reverse_rotate('b', b);
}
