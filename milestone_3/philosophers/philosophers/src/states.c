/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:37:00 by mario             #+#    #+#             */
/*   Updated: 2026/04/09 20:46:06 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void sleep_philo(t_philo *philo)
{
    print_status(philo, "is sleeping");
    smart_sleep(philo->params->time_to_sleep, philo);
}

void think(t_philo *philo)
{
    print_status(philo, "is thinking");
}

void get_forks(t_philo *philo, pthread_mutex_t **first, pthread_mutex_t **second)
{
    int left = philo->id;
    int right = philo->id % philo->params->num_of_philos + 1;
    if (left < right)
    {
        *first = &philo->mutex->forks[left];
        *second = &philo->mutex->forks[right];
    }
    else
    {
        *first = &philo->mutex->forks[right];
        *second = &philo->mutex->forks[left];
    }
}

void eat(t_philo *philo)
{
    pthread_mutex_t *first;
    pthread_mutex_t *second;
    get_forks(philo, &first, &second);

    pthread_mutex_lock(first);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(second);
    print_status(philo, "has taken a fork");

    pthread_mutex_lock(&philo->mutex->meal_lock);
    philo->last_meal = ft_get_time();
    philo->meals_eaten++;
    if (philo->meals_eaten == philo->params->num_times_to_eat)
        philo->full = 1;
    pthread_mutex_unlock(&philo->mutex->meal_lock);

    print_status(philo, "is eating");
    smart_sleep(philo->params->time_to_eat, philo);

    pthread_mutex_unlock(second);
    pthread_mutex_unlock(first);
}
