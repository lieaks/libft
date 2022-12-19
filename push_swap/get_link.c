#include "push_swap.h"

void	get_link(t_stack **a, t_stack **b)
{
	elem	*a_a;
	elem	*b_b;

	a_a = (*a)->first;
	b_b = (*b)->first;
	while (b_b)
	{
		a_a = (*a)->first;
		while (a_a)
		{
			if(a_a->index > b_b->index && a_a->index < b_b->link->index)
				b_b->link = a_a;
			a_a = a_a->next;
		}
		b_b->cost = 0;
		b_b = b_b->next;
	}
}
