/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 00:47:46 by mario             #+#    #+#             */
/*   Updated: 2026/04/03 13:19:56 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int main(int ac, char **av)
{
    if (ac < 5 || ac > 6)
    {
        printf("Usage: ./philo n t_die t_eat t_sleep [max]\n");
        return 1;
    }

    t_data d;

    d.n_philos = atoi(av[1]);
    d.time_to_die = atoi(av[2]);
    d.time_to_eat = atoi(av[3]);
    d.time_to_sleep = atoi(av[4]);

    if (ac == 6)
        d.max_meals = atoi(av[5]);
    else
        d.max_meals = -1;

    d.max_meals = -1;
    d.simulation_ended = 0;
    d.eating_count = 0;
    d.start_time = now_ms();

    pthread_mutex_init(&d.print_lock, NULL);
    pthread_mutex_init(&d.meal_lock, NULL);

    // FORKS
    d.forks = malloc(sizeof(pthread_mutex_t) * d.n_philos);
    int i = 0;
    while (i < d.n_philos)
    {
        pthread_mutex_init(&d.forks[i], NULL);
        i++;
    }

    t_philo *p = malloc(sizeof(t_philo) * d.n_philos);
    pthread_t *t = malloc(sizeof(pthread_t) * d.n_philos);

    i = 0;
    while (i < d.n_philos)
    {
        p[i].id = i;
        p[i].meals = 0;
        p[i].data = &d;

        pthread_mutex_lock(&d.meal_lock);
        p[i].last_meal = d.start_time;
        pthread_mutex_unlock(&d.meal_lock);

        pthread_create(&t[i], NULL, philo_routine, &p[i]);
        i++;
    }

    // monitor
    monitor_philosophers(p, &d);

    cleanup(p, t, &d);

    return (0);
}
