/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:47:46 by mario             #+#    #+#             */
/*   Updated: 2026/04/10 14:02:29 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static int	create_threads(t_data *data)
{
	int	i;

	i = 1;
	data->params.time_start = ft_get_time();
	while (i <= data->params.num_of_philos)
	{
		data->philos[i].last_meal = data->params.time_start;
		if (pthread_create(&data->philos[i].thread,
				NULL, routine, &data->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	init_philos(t_data *data)
{
	int	i;
	int	n;

	i = 1;
	n = data->params.num_of_philos;
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

static int	init_mutexes(t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->params.num_of_philos)
	{
		if (pthread_mutex_init(&data->mutex.forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->mutex.meal_lock, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex.dead_lock, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex.print_lock, NULL))
		return (1);
	return (0);
}

static void	init_program(t_data *data, int ac, char **av)
{
	data->params.num_of_philos = ft_atol(av[1]);
	data->params.time_to_die = ft_atol(av[2]);
	data->params.time_to_eat = ft_atol(av[3]);
	data->params.time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		data->params.num_times_to_eat = ft_atol(av[5]);
	else
		data->params.num_times_to_eat = -1;
	data->params.dead_flag = 0;
	data->params.time_start = ft_get_time();
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parse_args(ac, av))
		return (1);
	init_program(&data, ac, av);
	if (alloc_data(&data))
		return (1);
	init_philos(&data);
	if (init_mutexes(&data))
	{
		free_data(&data);
		return (1);
	}
	if (create_threads(&data))
	{
		destroy_mutexes(&data);
		free_data(&data);
		return (1);
	}
	monitor(&data);
	if (join_threads(&data))
		return (1);
	destroy_mutexes(&data);
	free_data(&data);
	return (0);
}
