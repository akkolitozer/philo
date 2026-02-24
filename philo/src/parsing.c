/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:35:58 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/24 01:24:30 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parser_args(t_rules *rules, char **av)
{
	int	i;
	int	error;
	
	i = 0;
	error = 0;
	while (av[++i])
	{
		if (i == 1)
			rules->philo_numbers = ft_atoi(av[i], &error);
		if (i == 2)
			rules->time_to_die = ft_atoi(av[i], &error);
		if (i == 3)
			rules->time_to_eat = ft_atoi(av[i], &error);
		if (i == 4)
			rules->time_to_sleep = ft_atoi(av[i], &error);
		if (i == 5)
			rules->number_of_meals = ft_atoi(av[i], &error);
	}
	return (error);
}
