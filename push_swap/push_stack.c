#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	elem	*tmp;

	if ((*src)->first == NULL)
		return ;
	tmp = (*src)->first;
	(*src)->first = (*src)->first->next;
	(*src)->first->prev = NULL;
	if ((*dest)->first != NULL)
		(*dest)->first->prev = tmp;
	tmp->next = (*dest)->first;
	(*dest)->first = tmp;
}
