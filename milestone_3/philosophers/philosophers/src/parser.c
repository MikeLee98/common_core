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

int is_positive_number(const char *str)
{
    int i = 0;

    if (!str || str[0] == '\0')
        return 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }

    return 1;
}

int parse_args(int ac, char **av)
{
    int i;

    if (ac != 5 && ac != 6)
    {
        printf("Usage: ./philo n t_die t_eat t_sleep [max]\n");
        return 1;
    }
    i = 1;
    while (i < ac)
    {
        if (!is_positive_number(av[i]))
        {
            printf("Usage: ./philo n t_die t_eat t_sleep [max]\n");
            return 1;
        }
        i++;
    }
    if (ft_atol(av[1]) == 1)
    {
        single(av);
		return (1);
    }
    return 0;
}
