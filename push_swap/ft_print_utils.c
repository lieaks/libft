/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:14:45 by dly               #+#    #+#             */
/*   Updated: 2022/12/20 15:23:44 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int	ft_size_itoa(long n)
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
	long	nb;
	size_t	i;

	nb = (long)n;
	i = ft_size_itoa(nb);
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	i--;
	if (nb == 0)
		ptr[0] = '0';
	else if (nb < 0)
	{
		ptr[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		ptr[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	return (ptr);
}

int	ft_len_nb(unsigned long long ptr, char *base)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count++;
		return (count);
	}
	while (ptr > 0)
	{
		count++;
		ptr /= ft_strlen(base);
	}
	return (count);
}

int	ft_itoa_base(unsigned long long nb, char *base)
{
	int			len;
	char		*result;

	len = ft_len_nb(nb, base);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	len--;
	if (nb == 0)
		result[0] = base[0];
	while (nb > 0)
	{
		result[len--] = base[nb % ft_strlen(base)];
		nb /= ft_strlen(base);
	}
	write(1, result, ft_strlen(result));
	free(result);
	return (1);
}

