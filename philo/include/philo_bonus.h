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
/* INT_MAX */
# include <limits.h>

struct s_info;

typedef struct	s_philo
{
	pthread_t	th;
	int			id;
	int			eat_count;
	long long 	last_meal;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork; 
	struct s_info		*rules;
}		t_philo;

typedef struct	s_info
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	long long	start_time;
	bool			end;
	bool			all_eat;
	int				nb_ph_ate;
	t_philo			*philo;
	pthread_mutex_t	printing; 
	pthread_mutex_t	meal; 
	pthread_mutex_t	dead; 
	pthread_mutex_t	stop; 
}		t_info;

/* init.c */
int	init_all(t_info *rules, char **av);

/* free.c */
void	free_all(t_info *rules);

/* utils.c */
int				ft_atoi(const char *nptr);
long long	timestamp();
void	waiting(long long time);
void	print_action(t_philo *p, int id, char *str);
int	is_dead(t_philo *p, int nb);

/* philo.c */
int	simulation(t_info *rules);

#endif