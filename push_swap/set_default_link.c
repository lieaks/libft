#include "push_swap.h"

void	set_default_link(t_stack **a, t_stack **b)
{
	elem	*a_a;
	elem	*b_b;

	a_a = (*a)->first;
	b_b = (*b)->first;
	while (b_b)
	{
		b_b->link = a_a;
		b_b = b_b->next;
	}
	while (a_a)
	{
		a_a->link = a_a;
		a_a = a_a->next;
	}
}
