/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:33:31 by dly               #+#    #+#             */
/*   Updated: 2022/12/29 20:34:24 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ready_checker(t_stack **a, t_stack **b)
{
	init_stack(b);
	if (!is_valid_dup(*a) || !*b)
	{
		free_stack(a);
		free_stack(b);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	assign_rank(a);
}

void	apply_ope(char *ope, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(ope, "sa\n"))
		swap('x', a);
	else if (!ft_strcmp(ope, "sb\n"))
		swap('x', b);
	else if (!ft_strcmp(ope, "ss\n"))
		ss('x', a, b);
	else if (!ft_strcmp(ope, "pa\n"))
		push('x', b, a);
	else if (!ft_strcmp(ope, "pb\n"))
		push('x', a, b);
	else if (!ft_strcmp(ope, "ra\n"))
		rotate('x', a);
	else if (!ft_strcmp(ope, "rb\n"))
		rotate('x', b);
	else if (!ft_strcmp(ope, "rr\n"))
		rr('x', a, b);
	else if (!ft_strcmp(ope, "rra\n"))
		reverse_rotate('x', a);
	else if (!ft_strcmp(ope, "rrb\n"))
		reverse_rotate('x', b);
	else if (!ft_strcmp(ope, "rrr\n"))
		rrr('x', a, b);
	else
		exit_err();
}

void	ope_stdin(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_ope(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (!(*b)->first && a && is_sorted((*a)->first))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	fill_stack(&a, ac, av);
	ready_checker(&a, &b);
	ope_stdin(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
