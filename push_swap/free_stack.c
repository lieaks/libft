/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:30 by dly               #+#    #+#             */
/*   Updated: 2022/12/29 17:41:53 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack	**stack)
{
	t_elem	*tmp;
	t_elem	*current;

	if (!*stack)
		return ;
	current = (*stack)->first;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	(*stack)->first = NULL;
	free(*stack);
	*stack = NULL;
}
