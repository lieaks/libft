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

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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
/* fork*/
# include <sys/types.h>
/* semaphore */
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

struct s_info;

typedef struct	s_philo
{
	pid_t			pid;
	int				id;
	int				eat_count;
	long long 		last_meal;
	struct s_info	*rules;
}		t_philo;

typedef struct	s_info
{
	int				idx;
	sem_t			*sem_dead;
	sem_t			*sem_print;
	sem_t			*sem_stop;
	sem_t			*sem_fork;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	long long		start_time;
	bool			end;
	bool			all_eat;
	int				nb_ph_ate;
	t_philo			*philo;
}		t_info;

/* init.c */
int	init_all(t_info *rules, char **av);

/* free.c */
void	free_all(t_info *rules);

/* utils.c */
int				ft_atoi(const char *nptr);
long long	timestamp();
void	ft_usleep(long long time);
void	print_action(t_philo *p, int id, char *str);
int	is_dead(t_philo *p, int nb);

/* philo.c */
int	simulation(t_info *rules);

#endif