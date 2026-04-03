/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 01:25:18 by mario             #+#    #+#             */
/*   Updated: 2026/04/03 13:28:08 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void monitor_philosophers(t_philo *p, t_data *d)
{
    int i = 0;

    while (!sim_end(d))
    {
        i = 0;
        while (i < d->n_philos)
        {
            pthread_mutex_lock(&d->meal_lock);
            if (now_ms() - p[i].last_meal > d->time_to_die)
            {
                pthread_mutex_lock(&d->print_lock);
                printf("%ld %d died\n",
                now_ms() - d->start_time, p[i].id);
                pthread_mutex_unlock(&d->print_lock);

                d->simulation_ended = 1;
                break ;
            }
            pthread_mutex_unlock(&d->meal_lock);
            i++;
        }
        usleep(1000);
    }
}
