/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:10:28 by dly               #+#    #+#             */
/*   Updated: 2023/01/31 18:10:47 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

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
	rules->sem_fork = sem_open(rules->sema_name, O_CREA, 0644,rules->nb_philo);
	while (rules->idx < rules->nb_philo)
	{
		rules->philo->pid = fork();
		if (rules->philo->pid == 0)
		{
			if (sem_open(rules->sema_name, O_CREA, 0644,rules->nb_philo))
				exit();
				while (1)
				{
					sem_wait(rules->sem_fork);
					print_action(rules, rules->idx, "has taken a fork");
					sem_wait(rules->sem_fork);
					print_action(rules, rules->idx, "has taken a fork");
					print_action(rules, rules->idx, "is eating");
					rules->philo->last_meal = timestamp();
					rules->philo->eat_count++;
					waiting(rules->time_to_sleep);
					sem_post(rules->sem_fork);
					sem_post(rules->sem_fork);
					print_action(rules, rules->idx, "is eating");
					waiting(rules->time_to_eat);
					print_action(rules, rules->idx, "is thinking");
					if (rules->philo->eat_count == rules->max_eat)
						break ;
				}
			if (sem_close(rules->sem_fork) == -1) 
				exit();
			exit ();
		}
		rules->idx++;
	}
	sem_unlink(rules->sema_name);
	return (0);
}