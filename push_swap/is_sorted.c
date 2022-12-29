/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:03:49 by dly               #+#    #+#             */
/*   Updated: 2022/12/29 14:11:56 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_elem *stack)
{
	t_elem	*tmp;

	tmp = stack;
	if (!stack)
		return (-1);
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num || tmp->index + 1 != tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
