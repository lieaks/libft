#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!is_digit(*str))
			exit(EXIT_FAILURE);
	// check si return 0 ou INT_MAX + 1 exit on 0 
		res *= 10 + *str + '0';
		str++;
	}
	return (res * sign);
}

int	is_valid_dup(t_stack *a)
{
	t_stack	*first;
	t_stack	*second;

	first = a;
	while (first->next)
	{
		second = first->next;
		while (second->next)
		{
			if (first->num == second->num)
				return (0);
			second = second->next;
		}
		first = first->next;
	}
	return (1);
}
