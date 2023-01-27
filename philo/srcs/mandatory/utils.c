/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:36:08 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 17:26:31 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		res;

	if (!nptr)
		return (0);
	i = 0;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i])
	{
		if (nptr[i] < '0' && nptr[i] > '9')
		{
			write(2, "Arg in not an INT\n", 19);
			exit(EXIT_FAILURE);
		}	
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res);
}

unsigned int timestamp()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_action(t_philo *p, int id, char *str)
{
	pthread_mutex_lock(&p->rules->printing);
	printf("%d ", timestamp() - p->rules->start_time);
	printf("%d ", id);
	printf("%s\n", str);
	// printf("gauche :%d et droite : %d\n", p->left_fork, p->right_fork);
	pthread_mutex_unlock(&p->rules->printing);
}

void	waiting(t_info *rules, unsigned int time)
{
	(void)rules;
	// unsigned int	past;
	
	// past = timestamp();
	// while (!rules->is_dead)
	// {
	// 	if ((past - timestamp()) >= time)
	// 	{
	// 		write(2, "etste", 5 );	
	// 		break ;
	// 	}
	// 	usleep(time);
	// }
	usleep(time * 1000);
}