#include "push_swap.h"

int	smaller_in_stack(t_stack *a)
{
	elem	*e;
	int		num;

	num = INT_MAX;
	e = a->first;
	while (e)
	{
		if (e->num <= num && !(e->index))
			num = e->num;
		e = e->next;
	}
 	return (num);
}

void	assign_rank(t_stack **a)
{
	elem 	*e;
	long	rank;

	rank = 1;
	e = (*a)->first;
	while(rank <= (*a)->length)
	{	
		if (e->num == smaller_in_stack(*a))
			e->index = rank++;
		e = e->next;
		if (!e)
			e = (*a)->first;
	}
}
