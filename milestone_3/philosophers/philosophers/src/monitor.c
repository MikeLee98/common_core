/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 01:25:18 by mario             #+#    #+#             */
/*   Updated: 2026/04/09 20:47:54 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int check_fullness(t_data *data)
{
    int i;
    int full_count;

    full_count = 0;
    i = 1;
    while (i <= data->params.num_of_philos)
    {
        pthread_mutex_lock(&data->mutex.meal_lock);
        if (data->philos[i].full == 1)
            full_count++;
        pthread_mutex_unlock(&data->mutex.meal_lock);

        if (full_count == data->params.num_of_philos)
        {
            pthread_mutex_lock(&data->mutex.dead_lock);
            data->params.dead_flag = 1;
            pthread_mutex_unlock(&data->mutex.dead_lock);
            return 0;
        }
        i++;
    }
    return 1;
}

int check_death(t_data *data)
{
    int i;
    long starve_time;
    int is_full;

    i = 1;
    while (i <= data->params.num_of_philos)
    {
        pthread_mutex_lock(&data->mutex.meal_lock);
        starve_time = ft_get_time() - data->philos[i].last_meal;
        is_full = data->philos[i].full;
        pthread_mutex_unlock(&data->mutex.meal_lock);

        if (starve_time >= data->params.time_to_die && !is_full)
        {
            pthread_mutex_lock(&data->mutex.dead_lock);
            data->params.dead_flag = 1;
            pthread_mutex_unlock(&data->mutex.dead_lock);

            pthread_mutex_lock(&data->mutex.print_lock);
            printf("%ld %d died\n",
                   ft_get_time() - data->params.time_start,
                   data->philos[i].id);
            pthread_mutex_unlock(&data->mutex.print_lock);

            return 0;
        }
        i++;
    }
    return 1;
}

void monitor(t_data *data)
{
	while (1)
	{
		if (!check_death(data) || !check_fullness(data))
			break ;
		usleep(500);
	}
}
