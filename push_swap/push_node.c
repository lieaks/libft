/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:45 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 18:30:46 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	elem	*tmp;

	if ((*src)->first == NULL)
		return ;
	tmp = (*src)->first;
	(*src)->first = (*src)->first->next;
	(*src)->first->prev = NULL;
	if ((*dest)->first != NULL)
		(*dest)->first->prev = tmp;
	tmp->next = (*dest)->first;
	(*dest)->first = tmp;
}
