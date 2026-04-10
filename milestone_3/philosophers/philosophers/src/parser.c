/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:38:58 by mario             #+#    #+#             */
/*   Updated: 2026/04/10 13:55:56 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str)
{
	long	num;
	int		i;

	num = 0;
	i = 0;
	if (!str || str[0] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		if (num > (LONG_MAX - (str[i] - '0')) / 10)
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

static int	validate_counts(long n_philos, long max_meals, int ac)
{
	if (n_philos < 1)
	{
		printf("Number of philosophers must be greater than 0\n");
		return (1);
	}
	if (ac == 6 && max_meals <= 0)
	{
		printf("Max meals must be greater than 0\n");
		return (1);
	}
	return (0);
}

static int	validate_times(long t_die, long t_eat, long t_sleep)
{
	if (t_die <= 0 || t_eat <= 0 || t_sleep <= 0)
	{
		printf("Time values must be greater than 0\n");
		return (1);
	}
	return (0);
}

static int	parse_values(char **av, int ac, long *out)
{
	out[0] = ft_atol(av[1]);
	out[1] = ft_atol(av[2]);
	out[2] = ft_atol(av[3]);
	out[3] = ft_atol(av[4]);
	if (ac == 6)
		out[4] = ft_atol(av[5]);
	else
		out[4] = -1;
	if (out[0] == -1 || out[1] == -1 || out[2] == -1 || out[3] == -1
		|| (ac == 6 && out[4] == -1))
	{
		printf("Usage: ./philosophers n t_die t_eat t_sleep [max]\n");
		return (1);
	}
	return (0);
}

int	parse_args(int ac, char **av)
{
	long	args[5];

	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philosophers n t_die t_eat t_sleep [max]\n");
		return (1);
	}
	if (parse_values(av, ac, args))
		return (1);
	if (validate_counts(args[0], args[4], ac))
		return (1);
	if (validate_times(args[1], args[2], args[3]))
		return (1);
	if (args[0] == 1)
	{
		single(av);
		return (1);
	}
	return (0);
}
