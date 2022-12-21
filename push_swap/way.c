/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:34:14 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 16:53:15 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check which of the function : "rotate()" or "reverse_rotate()"
 is the costless Default : reverse */
int	way(t_elem *b, t_stack *stack)
{
	t_elem	*current;
	int		nb_move;

	nb_move = 0;
	current = stack->first;
	while (current)
	{
		if (current == b && nb_move <= stack->length / 2)
			return (1);
		nb_move++;
		current = current->next;
	}
	return (0);
}
