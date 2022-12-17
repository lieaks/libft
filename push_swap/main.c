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

void	test(t_stack *stack)
{
	elem	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		if (tmp->link)
		{
			printf("num : %d  || rank : %ld  ", tmp->num, tmp->index);
			printf("link : %d\n", tmp->link->num);
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
	get_two_last(&a, &b);
	algo(&a,&b);
	test(a);
	printf("------------------\n");
	test(b);
	free_stack(&a);
	free_stack(&b);

	return (0);
}
