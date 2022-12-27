/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:57 by dly               #+#    #+#             */
/*   Updated: 2022/12/27 19:16:18 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char c, t_stack **stack)
{
	t_elem	*tmp;

	if (*stack == NULL || (*stack)->first->next == NULL)
		return ;
	tmp = (*stack)->first->next;
	(*stack)->first->next = tmp->next;
	(*stack)->first->prev = tmp;
	tmp->next = (*stack)->first;
	tmp->prev = NULL;
	(*stack)->first = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap('a', a);
	swap('b', b);
}
