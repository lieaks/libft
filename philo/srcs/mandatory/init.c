/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:35:04 by dly               #+#    #+#             */
/*   Updated: 2023/01/27 18:11:09 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	init_mutex(t_info *rules)
{
	if (pthread_mutex_init(&rules->stop, NULL))
	{
			free_all(rules);
			exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&rules->printing, NULL))
	{
			free_all(rules);
			exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&rules->meal, NULL))
	{
			free_all(rules);
			exit(EXIT_FAILURE);
	}
	if (pthread_mutex_init(&rules->dead, NULL))
	{
			free_all(rules);
			exit(EXIT_FAILURE);
	}
	return (0);
}

int	init_philo(t_info *rules)
{
	int	i;

	i = 0;
	rules->philo = malloc(rules->nb_philo * sizeof(t_philo));
	if (!rules->philo)
	{
		free_all(rules);
		exit(EXIT_FAILURE);
	}
	while (i < rules->nb_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].eat_count = 0;
		rules->philo[i].last_meal = 0;
		rules->philo[i].right_fork = NULL;
		rules->philo[i].rules = rules;
		rules->philo[i].last_meal = 0;
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
	if (av[5])
		rules->max_eat = ft_atoi(av[5]);
	else
		rules->max_eat = -1; 
	if (rules->nb_philo < 2)
		exit(EXIT_FAILURE);
	rules->start_time = timestamp();
	rules->end = false;
	rules->all_eat = false;	
	rules->nb_ph_ate = 0;
	init_mutex(rules);
	init_philo(rules);
	return (1);
}