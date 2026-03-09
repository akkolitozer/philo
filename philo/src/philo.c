/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:18:55 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/10 00:06:43 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_philo **philo, t_rules *rules)
{
	int	i;

	rules->forks = ft_calloc(rules->philo_number, sizeof(pthread_mutex_t));
	if (!rules->forks)
		return (1);
	i = -1;
	while (++i < rules->philo_number)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			return (1);
		(*philo)[i].id = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % rules->philo_number;
		(*philo)[i].meals_eaten = 0;
		(*philo)[i].last_meal = rules->start;
		(*philo)[i].rules = rules;
		pthread_create(&((*philo)[i].thread), NULL, routine, &((*philo)[i]));
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *) arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!simstop(philo->rules))
	{
		takefork(philo);
		eat(philo);
		dropfork(philo);
		if (all_meals_eaten(philo))
			break ;
		printf("%d is sleeping\n", philo->id);
		usleep_hm(philo);
		printf("%d is thinking\n", philo->id);
	}
	return (NULL);
}