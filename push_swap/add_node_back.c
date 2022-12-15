/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:14 by dly               #+#    #+#             */
/*   Updated: 2022/12/15 19:51:23 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_stack **stack, elem **node)
{
	elem	*last;

	if (!stack || !node)
		return ;
	if ((*stack)->first)
	{
		last = (*stack)->last;
		(*stack)->last->next = *node;
		(*node)->prev = last;
		(*stack)->last = *node;
	}
	else
	{
		(*stack)->first = *node;
		(*stack)->last = *node;
	}
	(*stack)->length++;
}
