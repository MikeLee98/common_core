/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 02:26:01 by mario             #+#    #+#             */
/*   Updated: 2026/04/03 13:18:13 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void *philo_routine(void *arg)
{
    t_philo *p = (t_philo *)arg;
    int left = p->id;
    int right = (p->id + 1) % p->data->n_philos;
	int first;
	int second;	

	if (p->id % 2 == 0)
	{
		first = left;
		second = right;
	}
	else
	{
		first = right;
		second = left;
	}

    pthread_mutex_lock(&p->data->meal_lock);
    p->last_meal = now_ms();
    pthread_mutex_unlock(&p->data->meal_lock);

    // 1 philosopher case
    if (p->data->n_philos == 1)
    {
        pthread_mutex_lock(&p->data->forks[left]);
        print_status(p, "has taken a fork");
        while (!sim_end(p->data))
            usleep(1000);
        pthread_mutex_unlock(&p->data->forks[left]);
        return NULL;
    }

    while (!sim_end(p->data) && (p->data->max_meals == -1 || p->meals < p->data->max_meals))
    {
        print_status(p, "is thinking");
		usleep(1000);

        pthread_mutex_lock(&p->data->forks[first]);
        print_status(p, "has taken a fork");

        pthread_mutex_lock(&p->data->forks[second]);
        print_status(p, "has taken a fork");

        pthread_mutex_lock(&p->data->meal_lock);
        p->last_meal = now_ms();
        pthread_mutex_unlock(&p->data->meal_lock);

        print_status(p, "is eating");
        p->meals++;
        usleep(p->data->time_to_eat * 1000);

        pthread_mutex_unlock(&p->data->forks[second]);
        pthread_mutex_unlock(&p->data->forks[first]);

        print_status(p, "is sleeping");
        usleep(p->data->time_to_sleep * 1000);
    }
    return NULL;
}
