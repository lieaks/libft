/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:37:19 by dly               #+#    #+#             */
/*   Updated: 2023/01/26 21:26:10 by dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	free_all(t_info *rules)
{
	int	i;

	i = 0;
	if (rules->philo)
		free(rules->philo);
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&rules->philo[i].left_fork);
		i++;
	}
	pthread_mutex_destroy(&rules->printing);
	pthread_mutex_destroy(&rules->meal);
}