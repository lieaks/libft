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
	waiting(p->rules->time_to_die + 1);
	pthread_mutex_lock(&p->rules->meal);
	pthread_mutex_lock(&p->rules->stop);
	if (!is_dead(p, 0) && timestamp() - p->last_meal >= p->rules->time_to_die)
	{
		pthread_mutex_unlock(&p->rules->meal);
		pthread_mutex_unlock(&p->rules->stop);
		print_action(p, p->id, "died");
		is_dead(p, 1);
		return (NULL);
	}
	pthread_mutex_unlock(&p->rules->meal);
	pthread_mutex_unlock(&p->rules->stop);
	return (NULL);
}

void *routine(void *rules)
{
	t_philo		*p;
	pthread_t	t;

	p = (t_philo*)rules;
	if (!(p->id % 2))
		waiting(p->rules->time_to_eat / 10);
	while (!is_dead(p, 0))
	{
		pthread_create(&t, NULL, routine_check_death, rules);
		pthread_mutex_lock(&p->left_fork);
		print_action(p, p->id, "has taken a fork");
		if (p->rules->nb_philo == 1)
		{
			waiting(p->rules->time_to_die * 2);
			return (NULL);
		}
		pthread_mutex_lock(p->right_fork);
		print_action(p, p->id, "has taken a fork");
		pthread_mutex_lock(&p->rules->meal);
		print_action(p, p->id, "is eating");
		p->last_meal = timestamp();
		p->eat_count++;
		pthread_mutex_unlock(&p->rules->meal);
		waiting(p->rules->time_to_eat);
		pthread_mutex_unlock(p->right_fork);
		pthread_mutex_unlock(&p->left_fork);
		print_action(p, p->id, "is sleeping");
		waiting(p->rules->time_to_sleep);
		print_action(p, p->id, "is thinking");
		if (p->eat_count == p->rules->max_eat)
		{
			pthread_mutex_lock(&p->rules->stop);
			p->rules->nb_ph_ate++;
			if (p->rules->nb_ph_ate == p->rules->nb_philo)
			{
				is_dead(p, 2);
				pthread_mutex_unlock(&p->rules->stop);
			}
			pthread_mutex_unlock(&p->rules->stop);
			break ;
		}
		pthread_detach(t);
	}
	return (NULL);
}

int	simulation(t_info *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		pthread_mutex_init(&(rules->philo[i].left_fork), NULL);
		// if (pthread_mutex_init(&(rules->philo[i].left_fork), NULL))
		// {
		// 	free_all(rules);
		// 	exit(EXIT_FAILURE);
		// }
		if (i == rules->nb_philo - 1)
			rules->philo[i].right_fork = &rules->philo[0].left_fork;
		else
			rules->philo[i].right_fork = &rules->philo[i + 1].left_fork;
		rules->philo->last_meal = timestamp();
		if (pthread_create(&rules->philo[i].th, NULL, &routine, &rules->philo[i]))
			return (1);
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_join(rules->philo[i].th, NULL))
			return (1);
		i++;
	}
	return (0);
}