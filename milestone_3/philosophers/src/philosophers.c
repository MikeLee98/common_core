/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:48:43 by mario             #+#    #+#             */
/*   Updated: 2026/03/29 08:47:23 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 2

pthread_mutex_t forks[N];

void *philo(void *arg)
{
    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;

    while (1)
    {
        printf("Philo %d is thinking\n", id);
        usleep(200000);

        printf("Philo %d tries to pick left fork %d\n", id, left);
        pthread_mutex_lock(&forks[left]);

        printf("Philo %d picked left fork %d\n", id, left);
        usleep(100000); // force interleaving

        printf("Philo %d tries to pick right fork %d\n", id, right);
        pthread_mutex_lock(&forks[right]);

        printf("Philo %d is eating\n", id);
        usleep(200000);

        pthread_mutex_unlock(&forks[right]);
        pthread_mutex_unlock(&forks[left]);

        printf("Philo %d put down forks\n", id);
        usleep(200000);
    }
}

int main(void)
{
    pthread_t threads[N];
    int ids[N];

    // init mutexes
    for (int i = 0; i < N; i++)
        pthread_mutex_init(&forks[i], NULL);

    // create threads
    for (int i = 0; i < N; i++)
    {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philo, &ids[i]);
    }

    // join threads (never ends)
    for (int i = 0; i < N; i++)
        pthread_join(threads[i], NULL);

    return 0;
}
