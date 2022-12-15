#include "push_swap.h"

void	swap(t_stack **stack)
{
	elem	*tmp;

	if (*stack == NULL || (*stack)->first->next == NULL)
		return ;
	tmp = (*stack)->first->next;
	(*stack)->first->next = tmp->next;
	(*stack)->first->prev = tmp;
	tmp->next = (*stack)->first;
	tmp->prev = NULL;
	(*stack)->first = tmp;

}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}