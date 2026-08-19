/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 23:20:32 by mario             #+#    #+#             */
/*   Updated: 2026/04/09 23:25:06 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	free_data(t_data *data)
{
	free(data->philos);
	free(data->mutex.forks);
}

void	destroy_mutexes(t_data *data)
{
	int	i;
	int	n;

	i = 1;
	n = data->params.num_of_philos;
	while (i <= n)
	{
		pthread_mutex_destroy(&data->mutex.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex.meal_lock);
	pthread_mutex_destroy(&data->mutex.dead_lock);
	pthread_mutex_destroy(&data->mutex.print_lock);
}

int	join_threads(t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->params.num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
