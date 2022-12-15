#include "push_swap.h"

void	rotate(t_stack **stack)
{
	elem	*tmp;

	if ((*stack)->first == NULL)
		return ;
	tmp = (*stack)->first;
	(*stack)->first = (*stack)->first->next;
	(*stack)->first->prev = NULL;
	tmp->prev = (*stack)->last->prev;
	tmp->next = NULL;
	(*stack)->last->next = tmp;
	(*stack)->last = tmp;
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack **stack)
{
	elem	*tmp;

	if((*stack)->first == NULL)
		return ;
	tmp = (*stack)->last;
	(*stack)->last = (*stack)->last->prev;
	(*stack)->last->next = NULL;
	tmp->prev = NULL;
	tmp->next = (*stack)->first;
	(*stack)->first->prev = tmp;
	(*stack)->first = tmp;
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
