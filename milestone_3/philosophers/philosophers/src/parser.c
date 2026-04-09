/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:38:58 by mario             #+#    #+#             */
/*   Updated: 2026/04/08 21:49:32 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int safe_atol(const char *str, long *result)
{
    long num = 0;
    int i = 0;

    if (!str || str[0] == '\0')
        return 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;

        if (num > (LONG_MAX - (str[i] - '0')) / 10)
            return 0;

        num = num * 10 + (str[i] - '0');
        i++;
    }

    *result = num;
    return 1;
}

int parse_args(int ac, char **av)
{
    int i;
    long values[5];

    if (ac != 5 && ac != 6)
    {
        printf("Usage: ./philo n t_die t_eat t_sleep [max]\n");
        return 1;
    }

    i = 1;
    while (i < ac)
    {
        if (!safe_atol(av[i], &values[i - 1]))
        {
            printf("Usage: ./philo n t_die t_eat t_sleep [max]\n");
            return 1;
        }
        i++;
    }

    // number of philosophers
    if (values[0] < 1)
    {
        printf("Number of philosophers must be at least 1\n");
        return 1;
    }

    // time values must be > 0
    if (values[1] <= 0 || values[2] <= 0 || values[3] <= 0)
    {
        printf("Time values must be greater than 0\n");
        return 1;
    }

    // optional max meals
    if (ac == 6 && values[4] <= 0)
    {
        printf("Max meals must be greater than 0\n");
        return 1;
    }

    if (values[0] == 1)
    {
        single(av);
        return 1;
    }

    return 0;
}
