/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:36:19 by dly               #+#    #+#             */
/*   Updated: 2022/12/29 20:57:15 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_elem
{
	int				num;
	long			index;
	struct s_elem	*link;
	int				cost;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct s_stack
{
	long	length;
	t_elem	*first;
	t_elem	*last;
}	t_stack;

long	ft_atoi(char *str);
int		is_valid_dup(t_stack *a);
void	add_node_back(t_stack **stack, t_elem **node);
t_elem	*new_node(int nb);
void	push(char c, t_stack **src, t_stack **dest);
void	push_ss(t_stack **a, t_stack **b);
void	swap(char c, t_stack **stack);
void	ss(char c, t_stack **a, t_stack **b);
void	rotate(char c, t_stack **stack);
void	reverse_rotate(char c, t_stack **stack);
void	rr(char c, t_stack **a, t_stack **b);
void	rrr(char c, t_stack **a, t_stack **b);
void	free_stack(t_stack	**stack);
void	fill_stack(t_stack **a, int ac, char **av);
void	init_stack(t_stack **stack);
void	ready_a_b(t_stack **a, t_stack **b);
int		smaller_in_stack(t_stack *a);
void	assign_rank(t_stack **a);
void	get_two_last(t_stack **a, t_stack **b);
void	get_link(t_stack **a, t_stack **b);
void	get_cost(t_stack **a, t_stack **b);
int		search_pos_in_a(t_stack *stack_a, t_elem *b, int half);
void	set_default_link(t_stack **a, t_stack **b);
t_elem	*get_lowest_cost(t_elem *b);
int		way(t_elem *b, t_stack *stack);
void	sorting(t_stack **a, t_stack **b);
t_elem	*search(int rank, t_elem *stack);
void	last_rotate(t_stack **a);
void	use_rr_rrr(t_stack **a, t_stack **b);
int		is_sorted(t_elem *stack);
void	sort_three(t_stack **a);
int		search_rr(t_elem *a, t_elem *b, int half);
int		search_rrr(t_elem *a, t_elem *b, int half);
void	get_first_cost(t_stack **a, t_stack **b);
void	get_last_cost(t_stack **a, t_stack **b);
int		ft_strcmp(const char *s1, const char *s2);
void	exit_err(void);
void	exit_free_err(t_stack **a, t_stack **b);
void	exit_all_free_err(t_stack **a, t_stack **b, char *line);

#endif