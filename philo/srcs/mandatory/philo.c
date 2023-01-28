/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:10:28 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 18:34:01 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	*routine_check_death(void *rules)
{
	t_philo	*p;

	p = (t_philo*)rules;
	
}

void *routine(void *rules)
{
	t_philo		*p;
	pthread_t	t;

	p = (t_philo*)rules;
	while (!p->rules->is_dead)
	{
		pthread_create(&t, NULL, routine_check_death, rules);
		pthread_mutex_lock(&p->rules->fork[p->left_fork]);
		print_action(p, p->id, "has taken a fork");
		pthread_mutex_lock(&p->rules->fork[p->right_fork]);
		print_action(p, p->id, "has taken a fork");
		pthread_mutex_lock(&p->rules->meal);
		print_action(p, p->id, "is eating");
		// // printf("nnb de atte 0%d\n", p->rules->nb_ate);
		p->last_meal = timestamp();
		p->rules->nb_ate += 1;
		pthread_mutex_unlock(&p->rules->meal);
		waiting(p->rules->time_to_eat);
		pthread_mutex_unlock(&p->rules->fork[p->right_fork]);
		pthread_mutex_unlock(&p->rules->fork[p->left_fork]);
		print_action(p, p->id, "is sleeping");
		waiting(p->rules->time_to_sleep);
		print_action(p, p->id, "is thinking");
	}
	return (NULL);
}

int	simulation(t_info *rules)
{
	// printf("%d\n", rules->max_eat);
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_create(&rules->philo[i].th, NULL, &routine, &rules->philo[i]))
			return (1);
		rules->philo[i].last_meal = timestamp();
		i++;
	}
	while (!(rules->all_eat))
	{
		i = 0;
		while (i < rules->nb_philo && !rules->is_dead)
		{
			// if ((rules->philo[i].last_meal - timestamp()) > (unsigned int)rules->time_to_die)
			// {
			// 	print_action(&rules->philo[i], i, "died");
			// 	rules->is_dead = true;
			// }
			usleep(150);
		printf("je simu %d\n", rules->nb_ate);
			i++;
		}
		if (rules->is_dead)
			break ;
		if (rules->nb_ate >= rules->max_eat)
		// {
			rules->all_eat = true;
		// 	break ;
		// }
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_join(rules->philo[i].th, NULL))
			return (1);
		i++;
	}
	free_all(rules);
	return (0);
}