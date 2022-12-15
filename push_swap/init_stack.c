#include "push_swap.h"

t_stack *init_stack(int ac, char **av)
{
	t_stack	*a;
	elem	*node;
	long	nb;
	int		i;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->first = NULL;
	a->last = NULL;
	a->length = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			free_stack(&a);
			exit(EXIT_FAILURE);
		}
		node = new_node((int)nb);
		if (!node)
		{
			free_stack(&a);
			exit(EXIT_FAILURE);
		}
		add_node_back(&a, &node);
		i++;
	}
	if (!is_valid_dup(a))
		return (NULL);
	printf("test : %d\n", is_valid_dup(a));
	return (a);
}
