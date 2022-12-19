#include "push_swap.h"

elem	*search(int rank, elem *stack)
{
	elem	*pos;

	pos = stack;
	while (pos)
	{
		if (rank == pos->index)
			return (pos);
		pos = pos->next;
	}
	return (NULL);
}

void	last_rotate(t_stack **a)
{
	elem	*one;

	one = search(1, (*a)->first);
	while ((*a)->first != one)
	{
		if (!check_rotate_faster(one, *a))
			reverse_rotate('a', a);	
		else
			rotate('a', a);
	}
}
