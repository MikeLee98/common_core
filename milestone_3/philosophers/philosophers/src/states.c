/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:37:00 by mario             #+#    #+#             */
/*   Updated: 2026/04/10 14:08:25 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	sleep_philo(t_philo *philo)
{
	print_status(philo, "is sleeping");
	smart_sleep(philo->params->time_to_sleep, philo);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void	get_forks(t_philo *philo, pthread_mutex_t **fst, pthread_mutex_t **snd)
{
	int	left;
	int	right;

	left = philo->id;
	right = philo->id % philo->params->num_of_philos + 1;
	if (left < right)
	{
		*fst = &philo->mutex->forks[left];
		*snd = &philo->mutex->forks[right];
	}
	else
	{
		*fst = &philo->mutex->forks[right];
		*snd = &philo->mutex->forks[left];
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_t	*fst;
	pthread_mutex_t	*snd;

	get_forks(philo, &fst, &snd);
	pthread_mutex_lock(fst);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(snd);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->meal_lock);
	philo->last_meal = ft_get_time();
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->params->num_times_to_eat)
		philo->full = 1;
	pthread_mutex_unlock(&philo->mutex->meal_lock);
	print_status(philo, "is eating");
	smart_sleep(philo->params->time_to_eat, philo);
	pthread_mutex_unlock(snd);
	pthread_mutex_unlock(fst);
}
