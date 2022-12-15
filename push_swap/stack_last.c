#include "push_swap.h"

elem	*last_node(t_stack *stack)
{
	elem	*last;

	if (!stack)
		return (NULL);
	last = stack->first;
	while (last->next)
		last = last->next;
	return (last);
}
