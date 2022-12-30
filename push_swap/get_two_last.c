/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_two_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:30:37 by dly               #+#    #+#             */
/*   Updated: 2022/12/30 15:13:44 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_two_last(t_stack **a, t_stack **b)
{
	long	two_last;

	two_last = (*a)->length - 2;
	if ((*a)->length == 3)
	{
		sort_three(a);
		return ;
	}
	while ((*a)->length > 3)
	{
		if (is_sorted((*a)->first))
			break ;
		while ((*a)->first->index >= two_last)
			rotate('a', a);
		if (!is_sorted((*a)->first))
			push('b', a, b);
		if ((*b)->first && (*b)->first->index <= two_last / 2)
			rotate('b', b);
	}
	sort_three(a);
}
