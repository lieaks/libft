/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:33:10 by dly               #+#    #+#             */
/*   Updated: 2022/12/26 19:58:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*search(int rank, t_elem *stack)
{
	t_elem	*pos;

	pos = stack;
	while (pos)
	{
		if (rank == pos->index)
			return (pos);
		pos = pos->next;
	}
	return (NULL);
}

void	last_rotate(t_stack **a)
{
	t_elem	*one;

	if (!(*a)->first->next)
		return ;
	one = search(1, (*a)->first);
	while ((*a)->first != one)
	{
		if (!way(one, *a))
			reverse_rotate('a', a);
		else
			rotate('a', a);
	}
}
