/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 02:48:43 by mario             #+#    #+#             */
/*   Updated: 2026/03/31 13:14:53 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <unistd.h>
// #include <sys/time.h>

// typedef struct s_data
// {
//     int n_philos;
//     int time_to_die;
//     int time_to_eat;
//     int time_to_sleep;
//     int max_meals; // -1 if unlimited
//     int simulation_ended;
//     long start_time;
//     pthread_mutex_t *forks;
//     pthread_mutex_t print_lock;
// } t_data;

// typedef struct s_philo
// {
//     int id;
//     int meals;
//     long last_meal;
//     t_data *data;
// } t_philo;

// long current_timestamp_in_ms(void)
// {
//     struct timeval tv;
//     gettimeofday(&tv, NULL);
//     return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
// }

// void print_status(t_philo *p, char *msg)
// {
//     pthread_mutex_lock(&p->data->print_lock);
//     if (!p->data->simulation_ended)
//         printf("%ld %d %s\n", current_timestamp_in_ms() - p->data->start_time, p->id, msg);
//     pthread_mutex_unlock(&p->data->print_lock);
// }

// void *philo_routine(void *arg)
// {
//     t_philo *p = (t_philo *)arg;
//     int left = p->id;
//     int right = (p->id + 1) % p->data->n_philos;
//     int first = left < right ? left : right;
//     int second = left < right ? right : left;

//     p->last_meal = current_timestamp_in_ms();
//     while ((p->data->max_meals == -1 || p->meals < p->data->max_meals) && !p->data->simulation_ended)
//     {
//         // thinking
//         print_status(p, "is thinking");

//         // pick forks
//         pthread_mutex_lock(&p->data->forks[first]);
//         print_status(p, "has taken a fork");
//         pthread_mutex_lock(&p->data->forks[second]);
//         print_status(p, "has taken a fork");

//         // eating
//         p->last_meal = current_timestamp_in_ms();
//         print_status(p, "is eating");
//         p->meals++;
//         usleep(p->data->time_to_eat * 1000);

//         // release forks
//         pthread_mutex_unlock(&p->data->forks[second]);
//         pthread_mutex_unlock(&p->data->forks[first]);

//         // sleeping
//         print_status(p, "is sleeping");
//         usleep(p->data->time_to_sleep * 1000);
//     }
//     return NULL;
// }

// int ft_atoi(const char *str)
// {
//     int i = 0, res = 0;
//     while (str[i] >= '0' && str[i] <= '9')
//         res = res * 10 + (str[i++] - '0');
//     return res;
// }

// int main(int argc, char **argv)
// {
//     if (argc < 5 || argc > 6)
//     {
//         printf("Usage: %s n_philos t_die t_eat t_sleep [max_meals]\n", argv[0]);
//         return 1;
//     }

//     t_data data;
//     data.n_philos = ft_atoi(argv[1]);
//     data.time_to_die = ft_atoi(argv[2]);
//     data.time_to_eat = ft_atoi(argv[3]);
//     data.time_to_sleep = ft_atoi(argv[4]);
//     data.max_meals = (argc == 6) ? ft_atoi(argv[5]) : -1;
//     data.simulation_ended = 0;
//     data.start_time = current_timestamp_in_ms();

//     pthread_mutex_init(&data.print_lock, NULL);
//     data.forks = malloc(sizeof(pthread_mutex_t) * data.n_philos);
//     for (int i = 0; i < data.n_philos; i++)
//         pthread_mutex_init(&data.forks[i], NULL);

//     t_philo *philos = malloc(sizeof(t_philo) * data.n_philos);
//     pthread_t *threads = malloc(sizeof(pthread_t) * data.n_philos);

//     for (int i = 0; i < data.n_philos; i++)
//     {
//         philos[i].id = i;
//         philos[i].meals = 0;
//         philos[i].last_meal = data.start_time;
//         philos[i].data = &data;
//         pthread_create(&threads[i], NULL, philo_routine, &philos[i]);
//     }

//     // monitor
//     while (!data.simulation_ended)
//     {
//         int all_done = 1;
//         for (int i = 0; i < data.n_philos; i++)
//         {
//             if (data.max_meals == -1 || philos[i].meals < data.max_meals)
//                 all_done = 0;

//             if (current_timestamp_in_ms() - philos[i].last_meal > data.time_to_die)
//             {
//                 pthread_mutex_lock(&data.print_lock);
//                 printf("%ld %d died\n", current_timestamp_in_ms() - data.start_time, philos[i].id);
//                 pthread_mutex_unlock(&data.print_lock);
//                 data.simulation_ended = 1;
//                 break;
//             }
//         }
//         if (all_done)
//             data.simulation_ended = 1;

//         usleep(1000);
//     }

//     for (int i = 0; i < data.n_philos; i++)
//         pthread_join(threads[i], NULL);

//     free(philos);
//     free(threads);
//     free(data.forks);
//     return 0;
// }

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

#define N 3
#define MAX_MEALS 3
#define TIME_TO_DIE 2000  // in milliseconds

typedef struct s_data
{
    pthread_mutex_t forks[N];
} t_data;

typedef struct s_philo
{
    int id;
    int meals;
    long last_meal;
    t_data *data;
} t_philo;

long current_timestamp_in_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void *philo(void *arg)
{
    t_philo *p = (t_philo *)arg;
    int left = p->id;
    int right = (p->id + 1) % N;
    int first, second;

    if (left < right)
    {
        first = left;
        second = right;
    }
    else
    {
        first = right;
        second = left;
    }

    p->meals = 0;
    p->last_meal = current_timestamp_in_ms();

    while (p->meals < MAX_MEALS)
    {
        printf("%ld %d is thinking\n", current_timestamp_in_ms(), p->id);

        pthread_mutex_lock(&p->data->forks[first]);
        printf("%ld %d has taken a fork\n", current_timestamp_in_ms(), p->id);

        pthread_mutex_lock(&p->data->forks[second]);
        p->last_meal = current_timestamp_in_ms();
        printf("%ld %d has taken a fork\n", current_timestamp_in_ms(), p->id);
        printf("%ld %d is eating\n", current_timestamp_in_ms(), p->id);

        p->meals++;

        pthread_mutex_unlock(&p->data->forks[second]);
        pthread_mutex_unlock(&p->data->forks[first]);

        printf("%ld %d is sleeping\n", current_timestamp_in_ms(), p->id);
    }

    return NULL;
}

int main(void)
{
    pthread_t threads[N];
    t_data data;
    t_philo philos[N];
    int i;

    // Initialize forks
    i = 0;
    while (i < N)
    {
        pthread_mutex_init(&data.forks[i], NULL);
        i++;
    }

    // Initialize philosophers
    i = 0;
    while (i < N)
    {
        philos[i].id = i;
        philos[i].meals = 0;
        philos[i].data = &data;
        philos[i].last_meal = current_timestamp_in_ms();
        i++;
    }

    // Create threads
    i = 0;
    while (i < N)
    {
        pthread_create(&threads[i], NULL, philo, &philos[i]);
        i++;
    }

    // Monitor philosophers
    int alive = 1;
    while (alive)
    {
        int all_done = 1;

        i = 0;
        while (i < N)
        {
            if (philos[i].meals < MAX_MEALS)
                all_done = 0;

            if (current_timestamp_in_ms() - philos[i].last_meal > TIME_TO_DIE)
            {
                printf("%ld %d died\n", current_timestamp_in_ms(), philos[i].id);
                alive = 0;
                break;
            }

            i++;
        }

        if (all_done)
            alive = 0;

        usleep(1000); // tiny sleep to prevent busy loop
    }

    // Join threads
    i = 0;
    while (i < N)
    {
        pthread_join(threads[i], NULL);
        i++;
    }

    return 0;
}
