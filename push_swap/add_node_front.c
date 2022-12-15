#include "push_swap.h"


void	add_node_front(t_stack **stack, elem **node)
{
	if (!stack || !node)
		return ;
	(*node)->next = (*stack)->first;
	(*stack)->first = *node;
}
