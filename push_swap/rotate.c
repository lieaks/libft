/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:52 by dly               #+#    #+#             */
/*   Updated: 2022/12/29 17:39:20 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(char c, t_stack **stack)
{
	t_elem	*tmp;
	t_elem	*last;
	t_elem	*first;

	if ((*stack)->first == NULL || (*stack)->first->next == NULL)
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
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(char c, t_stack **a, t_stack **b)
{
	rotate('r', a);
	rotate('r', b);
	if (c == 'a' || c == 'b')
		write(1, "rr\n", 3);
}

void	reverse_rotate(char c, t_stack **stack)
{
	t_elem	*tmp;
	t_elem	*el_last;
	t_elem	*el_first;

	if ((*stack)->first == NULL || (*stack)->first->next == NULL)
		return ;
	tmp = (*stack)->last;
	el_first = (*stack)->first;
	el_last = (*stack)->last->prev;
	el_first->prev = tmp;
	tmp->prev = NULL;
	tmp->next = el_first;
	el_last->next = NULL;
	(*stack)->first = tmp;
	(*stack)->last = el_last;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(char c, t_stack **a, t_stack **b)
{
	reverse_rotate('r', a);
	reverse_rotate('r', b);
	if (c == 'a' || c == 'b')
		write(1, "rrr\n", 4);
}
