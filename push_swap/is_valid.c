#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && ss1[i] && ss2[i] && i < n - 1)
		i++;
	return (ss1[i] - ss2[i]);
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

int	is_valid(t_stack *a)
{
	t_stack	*first;
	t_stack	*second;

	first = a;
	second = a;
	while (first->next)
	{
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