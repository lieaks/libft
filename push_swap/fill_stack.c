/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:27 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 18:30:28 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!is_digit(*str))
			return (2147483650);
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

elem	*new_node(int nb)
{
	elem	*ptr;

	ptr = (elem *)malloc(sizeof(elem));
	if (!ptr)
		return (NULL);
	ptr->num = nb;
	ptr->index = 0;
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->link = NULL;
	return (ptr);
}

void	add_node_back(t_stack **stack, elem **node)
{
	elem	*last;

	if (!stack || !node)
		return ;
	if ((*stack)->first)
	{
		last = (*stack)->last;
		(*stack)->last->next = *node;
		(*node)->prev = last;
		(*stack)->last = *node;
	}
	else
	{
		(*stack)->first = *node;
		(*stack)->last = *node;
	}
	(*stack)->length++;
}

void	fill_stack(t_stack **a, int ac, char **av)
{
	elem	*node;
	long	nb;
	int		i;

	init_stack(a);
	if (!a)
		return ;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		node = new_node((int)nb);
		if (nb > INT_MAX || nb < INT_MIN || !node)
		{
			free_stack(a);
			if (node)
				free(node);
			printf("Error\n");
			exit(EXIT_FAILURE);
		}
		add_node_back(a, &node);
		i++;
	}
}
