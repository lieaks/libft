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

void	rotate(t_stack **stack)
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
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
void	reverse_rotate(t_stack **stack)
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
}
// void	reverse_rotate(t_stack **stack)
// {
// 	elem	*tmp;

// 	if((*stack)->first == NULL)
// 		return ;
// 	tmp = (*stack)->last;
// 	(*stack)->last = tmp->prev;
// 	(*stack)->last->next = NULL;
// 	tmp->prev = NULL;
// 	tmp->next = (*stack)->first;
// 	(*stack)->first->prev = tmp;
// 	(*stack)->first = tmp;
// }

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
