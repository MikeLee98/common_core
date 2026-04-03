/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:48:30 by mario             #+#    #+#             */
/*   Updated: 2026/04/03 13:05:46 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data {
    int n_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int max_meals;

    int simulation_ended;
    int eating_count;

    long start_time;

    pthread_mutex_t *forks;
    pthread_mutex_t print_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t eat_lock;
} t_data;

typedef struct s_philo {
    int id;
    int meals;
    long last_meal;
    t_data *data;
} t_philo;

void *philo_routine(void *arg);
long now_ms(void);
int sim_end(t_data *d);
void set_end(t_data *d);
void print_status(t_philo *p, const char *msg);
int ft_atoi(const char *str);
void monitor_philosophers(t_philo *p, t_data *d);
void cleanup(t_philo *p, pthread_t *t, t_data *d);
