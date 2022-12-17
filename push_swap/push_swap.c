/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:35:12 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 20:24:52y dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ready_a_b(t_stack **a, t_stack **b)
{
	init_stack(b);
	if (!is_valid_dup(*a) || !*b)
	{
		free_stack(a);
		if (b)
			free_stack(b);
		exit(EXIT_FAILURE);
	}
}
int	lowest(t_stack *a)
{
	int	num;
	
	while (a->first)
	{
		if (a->first->num <= a->min && !(a->first->index))
			num = a->first->num; 
		a->first = a->first->next;
	}
	return (num);
}

void	parsing(t_stack **a)
{
	t_stack	*current;
	int		rank;

	rank = 1;
	current = *a;
	current->min = current->first->num;
	while(current->first)
	{
			
		if (current->first == NULL)
		{
			printf("lol");
			current->first = (*a)->first;
			printf("test %d\n",current->first->num);
			while (current->first)
			{
				if (current->first->num == current->min)
					current->first->index = rank++;
				current->first = current->first->next;
			}
			current->first = (*a)->first;
		}
		printf("num : %d   index : %d  min :%d\n",current->first->num, current->first->index, current->min);
		printf("adress %p\n",current->first);
	}
}
