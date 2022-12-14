#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{

}

void	push_ss(t_stack **a, t_stack **b)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (*a)->next;
	stack_b = (*b)->next;
	add_node_front(stack_a, *b);
	add_node_front(stack_b, *a);
}
