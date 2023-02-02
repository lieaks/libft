/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:29:00 by dly               #+#    #+#             */
/*   Updated: 2023/02/02 17:51:50 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo_bonus.h"

void	ft_take_fork(t_philo *p)
{
	sem_wait(p->rules->sem_fork);
	print_action(p, p->id, "has taken a fork");
	sem_wait(p->rules->sem_fork);
	print_action(p, p->id, "has taken a fork");
}

void	ft_eating(t_philo *p)
{
	print_action(p, p->id, "is eating");
	p->last_meal = timestamp();
	p->eat_count++;
	ft_usleep(p->rules->time_to_eat);
	sem_post(p->rules->sem_fork);
	sem_post(p->rules->sem_fork);
}

void	ft_sleeping(t_philo *p)
{
	print_action(p, p->id, "is sleeping");
	ft_usleep(p->rules->time_to_sleep);
	ft_usleep(p->rules->time_to_sleep);
}

