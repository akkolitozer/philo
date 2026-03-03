/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:18:55 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/03 16:17:03 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_philo **philo, t_rules *rules)
{
	int	i;

	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->philo_number);
	if (!rules->forks)
		return (0);
	i = -1;
	while (++i < rules->philo_number)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (0);
		(*philo)->id = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % rules->philo_number;
		(*philo)[i].last_meal = rules->start;
		(*philo)[i].meals_eaten = 0;
		(*philo)[i].rules = rules;
	}
	return (1);
}

void	go_routine(t_philo *philo)
{
	
}