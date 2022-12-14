/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:35:12 by dly               #+#    #+#             */
/*   Updated: 2022/12/14 17:36:01 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	*node;
	long	nb;
	int		i;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit(EXIT_FAILURE);
		node = new_node((int)nb);
		if (!node)
			return (NULL);
		add_node_back(&a, &node);
		i++;
	}
	if (!is_valid_dup(a))
		return (NULL);
	return (a);
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (1);
	push_swap(av);
	return (0);
}
