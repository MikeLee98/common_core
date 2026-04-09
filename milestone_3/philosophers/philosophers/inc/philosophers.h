/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:48:30 by mario             #+#    #+#             */
/*   Updated: 2026/04/08 22:15:36 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PHILO 201

typedef struct s_parameters
{
    long    time_start;
    int     num_of_philos;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    int     num_times_to_eat; // -1 if not specified
    int     dead_flag;

} t_parameters;

typedef struct s_mutex
{
    pthread_mutex_t  forks[MAX_PHILO];
    pthread_mutex_t  dead_lock;
    pthread_mutex_t  print_lock;
    pthread_mutex_t  philo_lock[MAX_PHILO];
    
} t_mutex;

typedef struct s_philo
{
    // Identity & thread
    int              id;
    pthread_t        thread;

    // State
    int              meals_eaten;
    long           last_meal;
    int              full;

    // Forks
    pthread_mutex_t  *l_fork;
    pthread_mutex_t  *r_fork;

    // Structs
    t_parameters     *params;
    t_mutex          *mutex;

} t_philo;

typedef struct s_data
{
    // Simulation parameters
    t_parameters     params;

    // Mutexes
    t_mutex          mutex;

    // Forks & philosophers
    t_philo          philos[MAX_PHILO];

} t_data;

#endif

void print_status(t_philo *philo, char *msg);
void smart_sleep(size_t time, t_philo *philo);
int sim_should_stop(t_philo *philo);
long ft_get_time(void);
void destroy_mutexes(t_data *data);
void single(char **av);
void init_philos(t_data *data);
int init_mutexes(t_data *data);
int create_threads(t_data *data);
int join_threads(t_data *data);
int parse_args(int ac, char **av);
int init_program(t_data *data, int ac, char **av);
void *philo_routine(void *arg);
void monitor(t_data *data);
void eat(t_philo *philo);
void sleep_philo(t_philo *philo);
void think(t_philo *philo);
int create(t_data *data);
int check_fullness(t_data *data);
int check_death(t_data *data);
void get_forks(t_philo *philo, pthread_mutex_t **first, pthread_mutex_t **second);
long ft_atol(const char *str);
