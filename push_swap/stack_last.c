#include "push_swap.h"

t_stack	*last_node(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
		return (NULL);
	last = stack;
	while (last->next)
		last = last->next;
	return (last);
}
