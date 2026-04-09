/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:47:46 by mario             #+#    #+#             */
/*   Updated: 2026/04/08 22:14:08 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int join_threads(t_data *data)
{
    int i;

    i = 1;
    while (i <= data->params.num_of_philos)
    {
        if (pthread_join(data->philos[i].thread, NULL))
            return (1);
        i++;
    }
    return (0);
}

int create_threads(t_data *data)
{
    int i;

    // Set start time BEFORE threads begin
    data->params.time_start = ft_get_time();

    i = 1;
    while (i <= data->params.num_of_philos)
    {
        data->philos[i].last_meal = data->params.time_start;

        if (pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]))
            return (1);
        i++;
    }
    return (0);
}

void init_philos(t_data *data)
{
    int i = 1;
    int n = data->params.num_of_philos;
    while (i <= n)
    {
        data->philos[i].id = i;
        data->philos[i].meals_eaten = 0;
        data->philos[i].last_meal = 0;
        data->philos[i].full = 0;
        data->philos[i].l_fork = &data->mutex.forks[i];
        data->philos[i].r_fork = &data->mutex.forks[i % n + 1];
        data->philos[i].params = &data->params;
        data->philos[i].mutex = &data->mutex;
        i++;
    }
}

int init_mutexes(t_data *data)
{
    int i = 1;
    while (i <= data->params.num_of_philos)
    {
        if (pthread_mutex_init(&data->mutex.forks[i], NULL))
            return (1);
        if (pthread_mutex_init(&data->mutex.philo_lock[i], NULL))
            return (1);
        i++;
    }
    if (pthread_mutex_init(&data->mutex.dead_lock, NULL))
        return (1);
    if (pthread_mutex_init(&data->mutex.print_lock, NULL))
        return (1);
    return (0);
}

int init_program(t_data *data, int ac, char **av)
{
    data->params.num_of_philos = atoi(av[1]);
    data->params.time_to_die = atoi(av[2]);
    data->params.time_to_eat = atoi(av[3]);
    data->params.time_to_sleep = atoi(av[4]);

    if (ac == 6)
        data->params.num_times_to_eat = atoi(av[5]);
    else
        data->params.num_times_to_eat = -1;

    data->params.dead_flag = 0;
    data->params.time_start = ft_get_time();

    if (data->params.num_of_philos > MAX_PHILO)
        return (1);

    return (0);
}

int create(t_data *data)
{
    // Initialize philosophers
    init_philos(data);
    
    // Initialize mutexes
    if (init_mutexes(data))
        return (1);

    // Create threads
    if (create_threads(data))
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    t_data  data;

    // Parse arguments
    if (parse_args(ac, av))
        return (1);

    // Initialize program
    if (init_program(&data, ac, av))
        return (1);

    // Create table
    if (create(&data))
    {
        destroy_mutexes(&data);
        return (1);
    }

    // Monitor
    monitor(&data);
    if (join_threads(&data))
        return (1);
    destroy_mutexes(&data);
    return (0);
}
