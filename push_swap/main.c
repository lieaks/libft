/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:41 by dly               #+#    #+#             */
/*   Updated: 2022/12/17 20:10:20 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	test(t_stack *stack)
{
	elem	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		if (tmp->link)
		{
		printf("num : %d  || rank : %ld  ", tmp->num, tmp->index);
			printf("link : %d    ||  cost : %d\n", tmp->link->num, tmp->cost);
		}
		tmp = tmp->next;
	}
	printf("stack length : %ld\n", stack->length);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (1);
	t_stack *a;
	t_stack *b;

	a = fill_stack(ac, av);
	ready_a_b(&a, &b);
	test(a);
	get_two_last(&a, &b);
	set_default_link(&a, &b);
	while (b->first)
	{
		get_link(&a,&b);
		get_cost(&a, &b);
		sorting(&a, &b);
	}
	test(a);
	printf("------------------\n");
	test(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
} 
