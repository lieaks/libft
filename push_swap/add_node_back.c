/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:14 by dly               #+#    #+#             */
/*   Updated: 2022/11/16 14:33:08 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_stack **stack, t_stack **node)
{
	t_stack	*last;

	if (!stack || !node)
		return ;
	if (*stack)
	{
		last = last_node(*stack);
		last->next = *node;
		(*node)->prev = last;
	}
	else
		stack = node;
}
