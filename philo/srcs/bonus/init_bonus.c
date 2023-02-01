/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:35:04 by dly               #+#    #+#             */
/*   Updated: 2023/01/31 15:13:06 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

int	init_semaphore(t_info *rules)
{
	sem_unlink("dead");
	sem_unlink("print");
	sem_unlink("stop");
	sem_unlink("fork");
	rules->dead = sem_open("dead", O_CREA, 0600, 1);
	rules->print = sem_open("print", O_CREA, 0600 , 1);
	rules->stop = sem_open("stop", O_CREA, 0600, 1);
	rules->fork = sem_open("fork", O_CREA, 0600, rules->nb_philo);
	if (rules->dead == SEM_FAILED ||rules->dead == SEM_FAILED ||
			rules->dead == SEM_FAILED || rules->dead == SEM_FAILED)
		return (1); 
	return (0);
}

int	init_philo(t_info *rules)
{
	int	i;

	i = 0;
	rules->philo = malloc(rules->nb_philo * sizeof(t_philo));
	if (!rules->philo)
		return (1);
	while (i < rules->nb_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].eat_count = 0;
		rules->philo[i].last_meal = 0;
		rules->philo[i].last_meal = 0;
		rules->philo[i].rules = rules;
		i++;
	}
	return (0);
}

int	init_all(t_info *rules, char **av)
{
	rules->nb_philo = ft_atoi(av[1]);
	rules->time_to_die = ft_atoi(av[2]);
	rules->time_to_eat = ft_atoi(av[3]);
	rules->time_to_sleep = ft_atoi(av[4]);
	if (rules-> nb_philo < 1 || rules->time_to_die < 0 ||
			rules->time_to_eat < 0 || rules->time_to_sleep < 0)
		return (1);
	if (av[5])
	{
		rules->max_eat = ft_atoi(av[5]);
			if (rules->max_eat < 0)
				return (1);
	}
	else
		rules->max_eat = -1; 
	rules->start_time = timestamp();
	rules->end = false;
	rules->all_eat = false;	
	rules->nb_ph_ate = 0;
	if (init_philo(rules))
		return (1);
	if (init_semaphore(rules))
		return (1);
	return (0);
}