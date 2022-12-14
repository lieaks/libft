#include "push_swap.h"


void	add_node_front(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->next = *stack;
	*stack = node;
}
