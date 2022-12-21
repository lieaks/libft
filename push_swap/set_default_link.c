/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:37:14 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 16:45:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_default_link(t_stack **a, t_stack **b)
{
	t_elem	*a_a;
	t_elem	*b_b;

	a_a = (*a)->first;
	b_b = (*b)->first;
	while (b_b)
	{
		b_b->link = a_a;
		b_b = b_b->next;
	}
	while (a_a)
	{
		a_a->link = a_a;
		a_a = a_a->next;
	}
}
