/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:36:19 by dly               #+#    #+#             */
/*   Updated: 2022/12/14 17:45:29 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack
{
	int		num;
	int		index;
	struct	s_stack *prev;
	struct	s_stack	*next;
}			t_stack;

int		ft_atoi(char *str);
int		is_digit(char c);
int		is_valid_dup(t_stack *a);
void	add_node_back(t_stack **a, t_stack **node);
t_stack	*new_node(int nb);
t_stack	*last_node(t_stack *stack);
void	push(t_stack **src, t_stack **dest);
void	push_ss(t_stack **a, t_stack **b);
void	add_node_front(t_stack **stack, t_stack *node);

#endif
