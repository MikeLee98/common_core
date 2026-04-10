/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:48:30 by mario             #+#    #+#             */
/*   Updated: 2026/04/10 13:57:39 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_parameters
{
	long	time_start;
	int		num_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		num_times_to_eat;
	int		dead_flag;
}	t_parameters;

typedef struct s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
}	t_mutex;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				meals_eaten;
	long			last_meal;
	int				full;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_parameters	*params;
	t_mutex			*mutex;
}	t_philo;

typedef struct s_data
{
	t_parameters	params;
	t_mutex			mutex;
	t_philo			*philos;
}	t_data;

void	print_status(t_philo *philo, char *msg);
void	smart_sleep(size_t time, t_philo *philo);
int		sim_should_stop(t_philo *philo);
long	ft_get_time(void);
void	destroy_mutexes(t_data *data);
void	single(char **av);
int		join_threads(t_data *data);
int		parse_args(int ac, char **av);
void	*routine(void *arg);
void	monitor(t_data *data);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);
void	get_forks(t_philo *philo, pthread_mutex_t **fst, pthread_mutex_t **snd);
long	ft_atol(const char *str);
int		alloc_data(t_data *data);
void	free_data(t_data *data);

#endif
