#include "libft.h"

int		ft_size_itoa(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	size_t	i;

	i = ft_size_itoa(n);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	i--;
	if (n == 0)
		ptr[0] = '0';
	else if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		ptr[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (ptr);
}