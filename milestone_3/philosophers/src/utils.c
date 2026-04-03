/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:52:06 by mario             #+#    #+#             */
/*   Updated: 2026/04/03 13:23:48 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

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

long now_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void cleanup(t_philo *p, pthread_t *t, t_data *d)
{
    int i;
    
    i = 0;
    while (i < d->n_philos)
    {
        pthread_join(t[i], NULL);
        i++;
    }

    i = 0;
    while (i < d->n_philos)
    {
        pthread_mutex_destroy(&d->forks[i]);
        i++;
    }

    pthread_mutex_destroy(&d->print_lock);
    pthread_mutex_destroy(&d->meal_lock);
    free(d->forks);
    free(p);
    free(t);
}

int sim_end(t_data *d)
{
    int val;

    pthread_mutex_lock(&d->meal_lock);
    val = d->simulation_ended;
    pthread_mutex_unlock(&d->meal_lock);
    return val;
}

void set_end(t_data *d)
{
    pthread_mutex_lock(&d->meal_lock);
    d->simulation_ended = 1;
    pthread_mutex_unlock(&d->meal_lock);
}

void print_status(t_philo *p, const char *msg)
{
    pthread_mutex_lock(&p->data->print_lock);
    if (!sim_end(p->data))
        printf("%ld %d %s\n",
            now_ms() - p->data->start_time,
            p->id,
            msg);
    pthread_mutex_unlock(&p->data->print_lock);
}
