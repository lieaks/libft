/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:30:27 by dly               #+#    #+#             */
/*   Updated: 2023/01/02 15:50:47 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *str)
{
	long	res;
	int		sign;
	long	error;

	error = 2147483650;
	res = 0;
	sign = 1;
	if (*str == '-')
	{
		if (ft_strlen(str) == 1 || ft_strlen(str) > 11)
			return (error);
		sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') || ft_strlen(str) > 10)
			return (error);
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

t_elem	*new_node(int nb)
{
	t_elem	*ptr;

	ptr = (t_elem *)malloc(sizeof(t_elem));
	if (!ptr)
		return (NULL);
	ptr->num = nb;
	ptr->index = 0;
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->link = NULL;
	return (ptr);
}

void	add_node_back(t_stack **stack, t_elem **node)
{
	t_elem	*last;

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
	t_elem	*node;
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
			exit_err();
		}
		add_node_back(a, &node);
		i++;
	}
}
