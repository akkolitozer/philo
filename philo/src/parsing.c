/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:35:58 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/14 17:10:48 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	one_philo(t_rules *rules)
{
	printf("0 1 has taken a fork\n");
	while (get_ms() < rules->start + rules->time_to_die)
		usleep(150);
	printf("%ld 1 died\n", get_ms() - rules->start);
	return (0);
}

void	parser_args(t_rules *rules, char **av)
{
	int	i;

	i = 0;
	rules->start = get_ms();
	rules->number_of_meals = -1;
	while (av[++i])
	{
		if (i == 1)
		{
			rules->philo_number = ft_atoi(av[i], rules);
			if (rules->philo_number > 200)
				rules->error = 1;
		}
		else if (i == 2 && !rules->error)
			rules->time_to_die = ft_atoi(av[i], rules);
		else if (i == 3 && !rules->error)
			rules->time_to_eat = ft_atoi(av[i], rules);
		else if (i == 4 && !rules->error)
			rules->time_to_sleep = ft_atoi(av[i], rules);
		else if (i == 5 && !rules->error)
			rules->number_of_meals = ft_atoi(av[i], rules);
	}
	rules->fed_philos = 0;
	if (rules->error || rules->philo_number < 1)
		printf("Error\nInvalid Arguments\n");
}
