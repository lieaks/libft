/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:29:28 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 16:43:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_link(t_stack **a, t_stack **b)
{
	t_elem	*a_a;
	t_elem	*b_b;

	a_a = (*a)->first;
	b_b = (*b)->first;
	while (b_b)
	{
		a_a = (*a)->first;
		while (a_a)
		{
			if (a_a->index > b_b->index && a_a->index < b_b->link->index)
				b_b->link = a_a;
			a_a = a_a->next;
		}
		b_b->cost = 0;
		b_b = b_b->next;
	}
}
