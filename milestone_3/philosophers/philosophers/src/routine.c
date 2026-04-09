/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 02:26:01 by mario             #+#    #+#             */
/*   Updated: 2026/04/09 20:49:11 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void *philo_routine(void *arg)
{
    t_philo *philo;
    int     is_full;

    philo = (t_philo *)arg;

    pthread_mutex_lock(&philo->mutex->meal_lock);
    philo->last_meal = ft_get_time();
    pthread_mutex_unlock(&philo->mutex->meal_lock);
	if (philo->id % 2 == 0)
		smart_sleep(10, philo);

    while (!sim_should_stop(philo))
    {
        eat(philo);
        if (sim_should_stop(philo))
            break ;
        pthread_mutex_lock(&philo->mutex->meal_lock);
        is_full = philo->full;
        pthread_mutex_unlock(&philo->mutex->meal_lock);

        if (is_full)
            break ;

        sleep_philo(philo);
        if (sim_should_stop(philo))
            break ;
        think(philo);
        usleep(500);
    }
    return (NULL);
}
