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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	fill_stack(&a, ac, av);
	ready_a_b(&a, &b);
	while (b->first)
	{
		get_link(&a, &b);
		get_cost(&a, &b);
		sorting(&a, &b);
	}
	last_rotate(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
