#include "push_swap.h"

void	free_stack(t_stack	**stack)
{
	elem	*tmp;

	if (!stack)
		return ;
	while ((*stack)->first)
	{
		tmp = (*stack)->first;
		free((*stack)->first);
		(*stack)->first = tmp;
	}
	(*stack)->first = NULL;
	free(*stack);
	*stack = NULL;
}