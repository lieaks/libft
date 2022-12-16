/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:23 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 19:34:47 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_front(t_stack **stack, elem **node)
{
	if (!stack || !node)
		return ;
	(*node)->next = (*stack)->first;
	(*stack)->first = *node;
	(*stack)->length++;
}
