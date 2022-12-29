/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:57 by dly               #+#    #+#             */
/*   Updated: 2022/12/29 20:35:03 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char c, t_stack **stack)
{
	t_elem	*un;
	t_elem	*deux;
	t_elem	*trois;

	if ((*stack)->length < 2 || !((*stack)->first) || !((*stack)->first->next))
		return ;
	un = (*stack)->first;
	deux = (*stack)->first->next;
	if ((*stack)->length > 2)
	{
		trois = (*stack)->first->next->next;
		un->next = deux->next;
		trois->prev = un;
	}
	else
		un->next = NULL;
	un->prev = deux;
	deux->prev = NULL;
	deux->next = un;
	(*stack)->first = deux;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(char c, t_stack **a, t_stack **b)
{
	swap('x', a);
	swap('x', b);
	if (c == 'a' || c == 'b')
		write(1, "ss", 2);
}
