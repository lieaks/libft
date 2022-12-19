#include "push_swap.h"

void	get_two_last(t_stack **a, t_stack **b)
{
	long	two_last;

	two_last = (*a)->length - 1;
	while ((*a)->length > 2)
	{
		while ((*a)->first->index >= two_last)
			rotate('a', a);
		push('b', a, b);
	}
	if ((*a)->first->index > (*a)->first->next->index)
		rotate('a', a);
}

