#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atoi(char *str)
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
			return (2147483650);
	// check si return 0 ou INT_MAX + 1 exit on 0 
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}

int	is_valid_dup(t_stack *a)
{
	elem	*left;
	elem	*current;

	current = a->first;
	while (current->next)
	{
		left = current;
		printf("TEST\n");
		while (left->next->next)
		{	
			if (left->num == left->next->num)
			{
				printf("wawa\n");
				return (0);
			}
			printf("first = %d vs sec = %d\n", left->num, left->next->num);
			left = left->next;
		}
		current = current->next;
	}
	return (1);
	// first = a->first;
	// while (first->next->next)
	// {
	// 	printf("TEST\n");
	// 	second = first->next;
	// 	while (second)
	// 	{
	// 		if (first->num == second->num)
	// 			return (0);
	// 		printf("first = %d vs sec = %d\n", first->num, second->num);
	// 		second = second->next;
	// 	}
	// 	first = first->next;
	// }
	// return (1);
}
