/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:36:19 by dly               #+#    #+#             */
/*   Updated: 2022/12/16 20:41:20 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>


typedef struct elem
{
	int			num;
	int			index;
	struct elem	*prev;
	struct elem	*next;
}				elem;

typedef struct	s_stack
{
	int	length;
	int		min;
	elem	*first;
	elem	*last;
}	t_stack;

long	ft_atoi(char *str);
int		is_digit(char c);
int		is_valid_dup(t_stack *a);
void	add_node_back(t_stack **stack, elem **node);
elem	*new_node(int nb);
elem	*last_node(t_stack *stack);
void	push(t_stack **src, t_stack **dest);
void	push_ss(t_stack **a, t_stack **b);
void	add_node_front(t_stack **stack, elem **node);
void	swap(t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rrr(t_stack **a, t_stack **b);
void	free_stack(t_stack	**stack);
t_stack *fill_stack(int ac, char **av);
void	init_stack(t_stack **stack);
void	ready_a_b(t_stack **a, t_stack **b);
void	parsing(t_stack **a);

#endif