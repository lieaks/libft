/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_two_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:30:37 by dly               #+#    #+#             */
/*   Updated: 2022/12/21 16:30:38 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_two_last(t_stack **a, t_stack **b)
{
	long	two_last;

	two_last = (*a)->length - 1;
	while ((*a)->length > 2)
	{
		while ((*a)->first->index >= two_last)
			rotate('a', a);
		push('b', a, b);
		if ((*b)->first->index <= two_last / 2)
			rotate('b', b);
		if ((*b)->last->index > (*b)->first->index)
			reverse_rotate('b', b);
	}
	if ((*a)->first->index > (*a)->first->next->index)
		rotate('a', a);
}

// void	get_two_last(t_stack **a, t_stack **b)
// {
// 	long	two_last;
// 	long	len;
// 	elem	*test;
// 	long	divi;
// 	int		sous;

// 	sous = 2;

// 	test = (*b)->first;
// 	len = (*a)->length;
// 	divi = (*a)->length / sous;
// 	two_last = (*a)->length / sous;
// 	printf("check %ld\n", two_last);
// 	while ((*a)->length > 2)
// 	{
// 		while ((*a)->first->index >= two_last)
// 		{
// 			printf("%ld     %ld\n", two_last, (*a)->first->index);
// 			rotate('a', a);
// 		}
// 		printf("  last%ld     index %ld\n", two_last, (*a)->first->index);
// 		push('b', a, b);
// 		if ((*b)->first->index < (*b)->last->index)
// 			rotate('b', b);

// 		if ((*a)->length == (*a)->length + two_last )
// 		{
// 			if (two_last == len - divi)
// 				two_last = len - 2;
// 			else
// 			two_last += divi;
// 		}
// 	}
// 	if ((*a)->first->index > (*a)->first->next->index)
// 		rotate('a', a);
// }

// void	get_two_last(t_stack **a, t_stack **b)
// {
// 	long	two_last;
// 	long	len;
// 	elem	*test;
// 	long	divi;
// 	int		sous;

// 	sous = 2;
// 	test = (*b)->first;
// 	len = (*a)->length;
// 	divi = (*a)->length / sous;
// 	two_last = (*a)->length / sous;
// 	if (sous == 1)
// 		two_last = len - 2;
// 	while ((*a)->length > 2)
// 	{
// 		if ((*a)->first->index <= two_last)
// 	{
// 			push('b', a, b);
// 			if ((*b)->first->index <= two_last / 2)
// 				rotate('b', b);
// 		}
// 		else if ((*a)->first->index > two_last)
// 		{
// 			rotate('a', a);
// 		}
// 		if (len == (*a)->length + two_last )
// 		{
// 			if (two_last == len - divi)
// 				two_last = len - 2;
// 			else
// 				two_last += divi;
// 		}
// 	}
// 	if ((*a)->first->index > (*a)->first->next->index)
// 		rotate('a', a);
// }