/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dly <dly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:48:25 by dly               #+#    #+#             */
/*   Updated: 2023/01/26 13:47:42y dly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* pthread */
# include <pthread.h>
/* gettimeofday */
# include <sys/time.h>
/* write */
# include <unistd.h>
/* malloc */
# include <stdlib.h>
/* exit */
# include <stdio.h>
// # include <time.h>
/* bool */
# include <stdbool.h>

struct s_info;

typedef struct	s_philo
{
	pthread_t	th;
	int			id;
	int			eat_count;
	int			left_fork;
	int			right_fork;
	unsigned int last_meal;
	struct s_info		*rules;
}		t_philo;

typedef struct	s_info
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	unsigned int	start_time;
	bool			is_dead;
	bool			all_eat;
	int				nb_ate;
	t_philo			*philo;
	pthread_mutex_t	*fork; 
	pthread_mutex_t	printing; 
	pthread_mutex_t	meal; 

}		t_info;

/* init.c */
int	init_all(t_info *rules, char **av);

/* free.c */
void	free_all(t_info *rules);

/* utils.c */
int				ft_atoi(const char *nptr);
unsigned int	timestamp();
void	waiting(t_info *rules, unsigned int time);

/* philo.c */
int	simulation(t_info *rules);
void	print_action(t_philo *p, int id, char *str);

#endif