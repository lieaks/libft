/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:54 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 18:30:55 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

elem	*last_node(t_stack *stack)
{
	elem	*last;

	if (!stack)
		return (NULL);
	last = stack->first;
	while (last->next)
		last = last->next;
	return (last);
}
