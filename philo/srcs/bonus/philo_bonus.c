/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:10:28 by dly               #+#    #+#             */
/*   Updated: 2023/02/01 17:05:10by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

void	ft_kill_all(t_info *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (rules->philo[i].pid)
			kill(rules->philo[i].pid, SIGTERM);
			i++;
	}
}

void	*check_death(void *philo)
{
	t_philo *p;
	int		i;

	p = (t_philo*)philo;
	i = 0;
	while (1)
	{
		if (timestamp() - p->last_meal > p->rules->time_to_die)
		{
			print_action(p, p->id, "died");
			while (i++ < p->rules->nb_philo)
				sem_post(p->rules->sem_stop);
			break ;
		}
	}
	return (NULL);
}

void	routine(t_philo *p)
{
	pthread_t	t;

	pthread_create(&t, NULL, check_death, p);
	pthread_detach(t);
	sem_wait(p->rules->sem_start);
	p->last_meal = timestamp();
	if (!(p->id % 2))
		ft_usleep(p->rules->time_to_eat / 10);
	while (p->eat_count != p->rules->max_eat)
	{
		ft_take_fork(p);
		ft_eating(p);
		ft_sleeping(p);
		print_action(p, p->id, "is thinking");
	}
	sem_post(p->rules->sem_stop);
	exit(EXIT_SUCCESS);
}

void	end_simulation(t_info *rules)
{
	if (rules->philo)
		free(rules->philo);
	sem_close(rules->sem_start);
	sem_close(rules->sem_print);
	sem_close(rules->sem_stop);
	sem_close(rules->sem_fork);
	sem_unlink("dead");
	sem_unlink("print");
	sem_unlink("stop");
	sem_unlink("fork");
}

int	wait_process(t_info *rules)
{
	int	i;

	i = 0;
	while (i++ < rules->nb_philo)
		sem_wait(rules->sem_stop);
	i = 0;
	while (i < rules->nb_philo)
	{
		kill(rules->philo[i].pid, SIGKILL);
		i++;
	}
	return (1);
}

int	simulation(t_info *rules)
{
	int	i;

	i = 0; 
	while (i < rules->nb_philo)
	{
		rules->philo[i].pid = fork();
		if (rules->philo[i].pid == 0)
			routine(&rules->philo[i]);
		if (rules->philo[i].pid < 0)
			return (1);
		i++;
	}
	i = 0; 
	while (i < rules->nb_philo)
	{
		sem_post(rules->sem_start);
		i++;
	}
	wait_process(rules);
	end_simulation(rules);
	return (0);
}
