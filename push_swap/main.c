/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:41 by dly               #+#    #+#             */
/*   Updated: 2022/12/19 17:58 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_stack *stack)
{
	elem	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		printf("num : %d  || rank : %ld\n", tmp->num, tmp->index);
		tmp = tmp->next;
	}
	printf("stack length : %ld\n", stack->length);
}

void	test_t(t_stack *stack)
{
	elem	*tmp;

	tmp = stack->last;
	while (tmp)
	{
		printf("num : %d  || rank : %ld\n", tmp->num, tmp->index);
		tmp = tmp->prev;
	}
	printf("stack length : %ld\n", stack->length);
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	if (ac < 2)
		return (1);
	fill_stack(&a, ac, av);
	ready_a_b(&a, &b);
	while (b->first)
	{
		get_link(&a,&b);
		get_cost(&a, &b);
		sorting(&a, &b);
	}
	last_rotate(&a);
	test(a);
	test(b);
	free_stack(&a);
	free_stack(&b);
	return (0);
} 
