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

void	*routine_check_death(void *rules)
{
	t_philo	*p;

	p = (t_philo*)rules;
	ft_usleep(p->rules->time_to_die);
		sem_wait(p->rules->sem_stop);
		sem_post(p->rules->sem_dead);
	if (!is_dead(p, 0) && timestamp() - p->last_meal >= p->rules->time_to_die)
	{
		// sem_post(p->rules->sem_stop);
		print_action(p, p->id, "died");
		is_dead(p, 1);
		sem_post(p->rules->sem_dead);
		return (NULL);
		sem_post(p->rules->sem_stop);
	}
	sem_wait(p->rules->sem_dead);
	exit(0);
	return (NULL);
}

void	*check_death(void *philo)
{
	t_philo *p;

	p = (t_philo*)philo;
	while (!p->rules->end)
	{
		ft_usleep(p->rules->time_to_die / 100);
		if (timestamp() - p->last_meal >= p->rules->time_to_die)
		{
			print_action(p, p->id, "died");
			p->rules->end = true;
			break ;
		}
		if (p->rules->max_eat != -1 && p->eat_count == p->rules->max_eat)
		{
			p->rules->end = true;
			break ;
		}
	}
	exit (1);
}

void	routine(t_philo *p)
{
	pthread_t	t;

	p->last_meal = timestamp();
	pthread_create(&t, NULL, check_death, p);
	if (!(p->id % 2))
		ft_usleep(p->rules->time_to_eat / 10);
	while (1)
	{
		ft_take_fork(p);
		ft_eating(p);
		ft_sleeping(p);
		print_action(p, p->id, "is thinking");
	}
	pthread_join(t, NULL);
}

void	end_simulation(t_info *rules)
{
	if (rules->philo)
		free(rules->philo);
	sem_close(rules->sem_dead);
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
	int	status;

	i = 0;

	while (i < rules->nb_philo)
	{
		waitpid(rules->philo[i].pid, &status, 0);
		// if (status != 0)
		// {
		// 	i = 0;
		// 	while (i++ < rules->nb_philo)
		// 		kill(rules->philo[i].pid, SIGKILL);
		// 	break;
		// }
		// ft_kill_all(rules);
		// waitpid(-1, NULL, 0);
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
		{
			routine(&rules->philo[i]);
			// ft_kill_all(rules);
		}
		if (rules->philo[i].pid < 0)
			return (1);
		i++;
	}
	wait_process(rules);
	end_simulation(rules);
	return (0);
}
