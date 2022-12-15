#include "push_swap.h"

void	test(t_stack *stack)
{
	elem	*tmp;

	tmp = stack->first;
	while (tmp)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (1);
	t_stack *a;
	t_stack *b;
	b = malloc(sizeof(t_stack));
	b->first = NULL;
	a = init_stack(ac, av);
	push(&b, &a);
	test(a);
	printf("------------------\n");
	test(b);

	return (0);
}
