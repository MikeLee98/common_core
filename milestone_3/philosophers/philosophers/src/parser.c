/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:38:58 by mario             #+#    #+#             */
/*   Updated: 2026/04/09 20:20:32 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	single(char **av)
{
	long	time;

	time = ft_atol(av[2]);
	printf("0 1 has taken a fork\n");
	usleep(time * 1000);
	printf("%ld 1 died\n", time);
}

long ft_atol(const char *str)
{
    long num = 0;
    int i = 0;

    if (!str || str[0] == '\0')
        return -1; // or some sentinel value for invalid input

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return -1; // invalid character

        if (num > (LONG_MAX - (str[i] - '0')) / 10)
            return -1; // overflow

        num = num * 10 + (str[i] - '0');
        i++;
    }

    return num;
}

int parse_args(int ac, char **av)
{
    if (ac != 5 && ac != 6)
    {
        printf("Usage: ./philosophers n t_die t_eat t_sleep [max]\n");
        return 1;
    }

    long n_philos   = ft_atol(av[1]);
    long t_die      = ft_atol(av[2]);
    long t_eat      = ft_atol(av[3]);
    long t_sleep    = ft_atol(av[4]);
    long max_meals;

    if (ac == 6)
        max_meals = ft_atol(av[5]);
    else
        max_meals = -1;

    // check for invalid conversion
    if (n_philos == -1 || t_die == -1 || t_eat == -1 || t_sleep == -1 || (ac == 6 && max_meals == -1))
    {
        printf("Usage: ./philosophers n t_die t_eat t_sleep [max]\n");
        return 1;
    }

    // number of philosophers
    if (n_philos < 1)
    {
        printf("Number of philosophers must be greater than 0\n");
        return 1;
    }

    // time values must be > 0
    if (t_die <= 0 || t_eat <= 0 || t_sleep <= 0)
    {
        printf("Time values must be greater than 0\n");
        return 1;
    }

    // optional max meals
    if (ac == 6 && max_meals <= 0)
    {
        printf("Max meals must be greater than 0\n");
        return 1;
    }

    if (n_philos == 1)
    {
        single(av);
        return 1;
    }

    return 0;
}
