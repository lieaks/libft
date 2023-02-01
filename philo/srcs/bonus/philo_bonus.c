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
	ft_usleep(p->rules->time_to_die + 1);
	sem_wait(p->rules->sem_stop);
	if (!is_dead(p, 0) && timestamp() - p->last_meal >= p->rules->time_to_die)
	{
		sem_post(p->rules->sem_stop);
		print_action(p, p->id, "died");
		is_dead(p, 1);
		return (NULL);
	}
	sem_post(p->rules->sem_stop);
	return (NULL);
}
void	ft_take_fork(t_philo *p)
{
	sem_wait(p->rules->sem_fork);
	print_action(p->rules, p->id, "has taken a fork");
	sem_wait(p->rules->sem_fork);
	print_action(p->rules, p->id, "has taken a fork");
}

void	ft_eating(t_philo *p)
{
	print_action(p->rules, p->id, "is eating");
	p->last_meal = timestamp();
	p->eat_count++;
	ft_usleep(p->rules->time_to_sleep);
	sem_post(p->rules->sem_fork);
	sem_post(p->rules->sem_fork);
}

void	ft_sleeping(t_philo *p)
{
	print_action(p->rules, p->id, "is eating");
	ft_usleep(p->rules->time_to_eat);
}

void	routine(t_philo *p)
{
	pthread_t	t;

	pthread_create(&t, NULL, routine_check_death, p->rules);
	if (!(p->id % 2))
		ft_usleep(p->rules->time_to_eat / 10);
	while (!is_dead(p, 0))
	{
		ft_take_fork(p->rules);
		ft_eating(p->rules);
		ft_sleeping(p->rules);
		print_action(p->rules, p->id, "is thinking");
		if (p->eat_count >= p->rules->max_eat)
			break ;
		if (p->rules->nb_philo == 1)
		{
			ft_usleep(p->rules->time_to_die * 2);
			return (NULL);
		}
	}
	pthread_detach(t);
}

void	end_simulation(t_info *rules)
{
	if (rules->philo)
		free(rules->philo);
	sem_close(rules->sem_dead);
	sem_close(rules->sem_print);
	sem_close(rules->sem_stop);
	sem_close(rules->sem_fork);
	sem_unlink(rules->sem_dead);
	sem_unlink(rules->sem_print);
	sem_unlink(rules->sem_stop);
	sem_unlink(rules->sem_fork);
}

int	simulation(t_info *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].pid = fork();
		if (rules->philo[i].pid == 0)
		{
			routine(&rules->philo[i]);
		}
		if (rules->philo[i].pid < 0)
			return (1);
		i++;
	}
	end_simulation(rules);
	return (0);
}
