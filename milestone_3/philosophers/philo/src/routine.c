/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 02:26:01 by mario             #+#    #+#             */
/*   Updated: 2026/04/10 14:08:27 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	philo_is_full(t_philo *philo)
{
	int	full;

	pthread_mutex_lock(&philo->mutex->meal_lock);
	full = philo->full;
	pthread_mutex_unlock(&philo->mutex->meal_lock);
	return (full);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->params->num_of_philos == 1)
	{
		single(philo);
		return (NULL);
	}
	pthread_mutex_lock(&philo->mutex->meal_lock);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->mutex->meal_lock);
	if (philo->id % 2 == 0)
		smart_sleep(10, philo);
	while (!sim_should_stop(philo))
	{
		eat(philo);
		if (sim_should_stop(philo) || philo_is_full(philo))
			break ;
		sleep_philo(philo);
		if (sim_should_stop(philo))
			break ;
		think(philo);
		usleep(500);
	}
	return (NULL);
}

void    single(t_philo *philo)
{
    long    time;

    time = philo->params->time_to_die;
    printf("0 1 has taken a fork\n");
    usleep(time * 1000);
    pthread_mutex_lock(&philo->mutex->dead_lock);
    philo->params->dead_flag = 1;
    pthread_mutex_unlock(&philo->mutex->dead_lock);
    printf("%ld 1 died\n", ft_get_time() - philo->params->time_start);
}
