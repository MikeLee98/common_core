/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:52:06 by mario             #+#    #+#             */
/*   Updated: 2026/04/08 22:01:52 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void print_status(t_philo *philo, char *msg)
{
    size_t time;

    pthread_mutex_lock(&philo->mutex->print_lock);

    if (sim_should_stop(philo))
    {
        pthread_mutex_unlock(&philo->mutex->print_lock);
        return;
    }
    
    time = ft_get_time() - philo->params->time_start;
    printf("%zu %d %s\n", time, philo->id, msg);

    pthread_mutex_unlock(&philo->mutex->print_lock);
}

void smart_sleep(size_t time, t_philo *philo)
{
    size_t start;

    start = ft_get_time();
    while (ft_get_time() - start < time)
    {
        if (sim_should_stop(philo))
            break;
        usleep(500);
    }
}

int sim_should_stop(t_philo *philo)
{
    int stop;

    pthread_mutex_lock(&philo->mutex->dead_lock);
    stop = philo->params->dead_flag;
    pthread_mutex_unlock(&philo->mutex->dead_lock);

    return (stop);
}

size_t ft_get_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL); // Could fail, but we won't handle that here for now
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void destroy_mutexes(t_data *data)
{
    int i = 0;

    while (i < data->params.num_of_philos)
    {
        pthread_mutex_destroy(&data->mutex.forks[i]);
        pthread_mutex_destroy(&data->mutex.philo_lock[i]);
        i++;
    }

    pthread_mutex_destroy(&data->mutex.dead_lock);
    pthread_mutex_destroy(&data->mutex.print_lock);
}

long ft_atol(const char *str)
{
    int i = 0;
    long sign = 1;
    long result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}
