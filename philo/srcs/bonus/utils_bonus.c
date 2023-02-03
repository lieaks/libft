/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:36:08 by dly               #+#    #+#             */
/*   Updated: 2023/02/01 15:45:55 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

int     ft_atoi(char *nptr)
{
        size_t  i;
        long             res;
        int             sign;

        if (!nptr)
                return (0);
        i = 0;
        res = 0;
        sign = 1;
        while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
                i++;
        if (nptr[i] == '-' || nptr[i] == '+')
        {
                if (nptr[i] == '-')
                        sign *= -1;
                i++;
        }
        while (nptr[i])
        {
			if (nptr[i] < '0' || nptr[i] > '9')
				return (-1);
            res *= 10;
			res += nptr[i] - '0';
			i++;
        }
        return (res * sign);
}
// int	ft_atoi(const char *nptr)
// {
// 	size_t	i;
// 	long	res;

// 	if (!nptr)
// 		return (0);
// 	i = 0;
// 	res = 0;
// 	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
// 		i++;
// 	while (nptr[i])
// 	{
// 		if (nptr[i] < '0' && nptr[i] > '9')
// 		{
// 			write(2, "Arg in not an INT\n", 19);
// 			exit(EXIT_FAILURE);
// 		}	
// 		res *= 10;
// 		res += nptr[i] - '0';
// 		i++;
// 	}
// 	// if (res <= 0 || res > INT_MAX)
// 	return (res);
// } 

long long timestamp()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_action(t_philo *p, int id, char *str)
{
	long long	time;

	sem_wait(p->rules->sem_print);
	time = timestamp() - p->rules->start_time;
	if (time >= 0 && time <= (long long)INT_MAX)
		printf("%lld %d %s\n", timestamp() - p->rules->start_time, id, str);
	sem_post(p->rules->sem_print);
}

void	ft_usleep(long long time)
{
	long long	past;
	
	past = timestamp();
	while ((timestamp() - past) < time)
		usleep(time / 10);
}
