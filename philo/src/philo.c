/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:18:55 by hulescur          #+#    #+#             */
/*   Updated: 2026/09/11 15:40:58 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	monitor(t_philo *philo)
{
	int		i;
	long	last_meal;

	while (1)
	{
		i = -1;
		while (++i < philo[0].rules->philo_number)
		{
			pthread_mutex_lock(&philo[i].rules->mmeal);
			last_meal = philo[i].last_meal;
			pthread_mutex_unlock(&philo[i].rules->mmeal);
			if (get_ms() - last_meal > philo[i].rules->time_to_die)
			{
				if (simstop(philo))
					return ;
				announce_death(&philo[i]);
				return ;
			}
		}
		usleep(500);
	}
}

int	init_mutexs(t_rules *rules)
{
	int	i;

	i = -1;
	rules->forks = ft_calloc(rules->philo_number, sizeof(pthread_mutex_t));
	if (!rules->forks)
		return (1);
	while (++i < rules->philo_number)
		if (pthread_mutex_init(&rules->forks[i], NULL))
			return (1);
	if (pthread_mutex_init(&rules->mstop, NULL))
		return (1);
	if (pthread_mutex_init(&rules->mwrite, NULL))
		return (1);
	if (pthread_mutex_init(&rules->mmeal, NULL))
		return (1);
	return (0);
}

void	destroy_mutexs(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->rules->philo_number)
		pthread_mutex_destroy(&philo->rules->forks[i]);
	pthread_mutex_destroy(&philo->rules->mstop);
	pthread_mutex_destroy(&philo->rules->mwrite);
	pthread_mutex_destroy(&philo->rules->mmeal);
	free(philo->rules->forks);
	free(philo->rules);
	free(philo);
}

int	init_philos(t_philo **philo, t_rules *rules)
{
	int	i;

	if (init_mutexs(rules))
		return (printf("Error initializing mutexs\n"));
	i = -1;
	while (++i < rules->philo_number)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = (i + 1) % rules->philo_number;
		(*philo)[i].meals_eaten = 0;
		(*philo)[i].last_meal = rules->start;
		(*philo)[i].rules = rules;
		(*philo)[i].fed = 0;
		if (pthread_create(&((*philo)[i].thread),
			NULL, routine, &((*philo)[i])))
			return (printf("Error creating thread for philo [%d]\n",
					(*philo)[i].id));
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		to_free;

	philo = (t_philo *) arg;
	start_routine(philo);
	while (!simstop(philo))
	{
		to_free = takefork(philo);
		if (!simstop(philo) && to_free)
			eat(philo);
		dropfork(philo, to_free);
		if (all_meals_eaten(philo))
			break ;
		if (!simstop(philo))
			printfm(philo, "is sleeping");
		usleep_hm(philo, philo->rules->tts);
		if (!simstop(philo))
		{
			printfm(philo, "is thinking");
			if (philo->rules->philo_number == 3)
				usleep_hm(philo, philo->rules->tte);
		}
		usleep(100);
	}
	return (NULL);
}
