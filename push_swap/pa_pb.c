/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:45 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 16:44:07 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(char c, t_stack **src, t_stack **dest)
{
	t_elem	*tmp;

	if ((*src)->first == NULL)
		return ;
	tmp = (*src)->first;
	if ((*src)->length > 1)
	{
		(*src)->first = (*src)->first->next;
		(*src)->first->prev = NULL;
	}
	else
		(*src)->first = NULL;
	if ((*dest)->first != NULL)
		(*dest)->first->prev = tmp;
	else
		(*dest)->last = tmp;
	tmp->next = (*dest)->first;
	(*dest)->first = tmp;
	(*dest)->length += 1;
	(*src)->length -= 1;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}
