/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:28:14 by hulescur          #+#    #+#             */
/*   Updated: 2026/08/14 12:18:39 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	simstop(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->mstop);
	if (philo->rules->stop == 1)
	{
		pthread_mutex_unlock(&philo->rules->mstop);
		return (1);
	}
	else if (philo->rules->stop == 2)
	{
		pthread_mutex_unlock(&philo->rules->mstop);
		return (2);
	}
	pthread_mutex_unlock(&philo->rules->mstop);
	return (0);
}

int	takefork(t_philo *philo)
{
	int	first;
	int	second;

	if (philo->left_fork < philo->right_fork)
		first = philo->left_fork;
	else
		first = philo->right_fork;
	if (philo->left_fork < philo->right_fork)
		second = philo->right_fork;
	else
		second = philo->left_fork;
	pthread_mutex_lock(&philo->rules->forks[first]);
	if (simstop(philo))
		return (pthread_mutex_unlock(&philo->rules->forks[first]), 0);
	printfm(philo, "has taken a fork");
	pthread_mutex_lock(&philo->rules->forks[second]);
	if (simstop(philo))
	{
		pthread_mutex_unlock(&philo->rules->forks[first]);
		pthread_mutex_unlock(&philo->rules->forks[second]);
		return (0);
	}
	printfm(philo, "has taken a fork");
	return (1);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->mmeal);
	philo->last_meal = get_ms();
	pthread_mutex_unlock(&philo->rules->mmeal);
	printfm(philo, "is eating");
	usleep_hm(philo, philo->rules->tte);
	pthread_mutex_lock(&philo->rules->mmeal);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->rules->mmeal);
}

void	dropfork(t_philo *philo, int to_free)
{
	if (to_free)
	{
		pthread_mutex_unlock(&philo->rules->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->rules->forks[philo->right_fork]);
	}
}

int	all_meals_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->mmeal);
	if (philo->rules->number_of_meals == -1)
	{
		pthread_mutex_unlock(&philo->rules->mmeal);
		return (0);
	}
	if (philo->meals_eaten >= philo->rules->number_of_meals && !philo->fed)
	{
		philo->fed = 1;
		philo->rules->fed_philos++;
		if (philo->rules->fed_philos >= philo->rules->philo_number)
		{
			pthread_mutex_unlock(&philo->rules->mmeal);
			pthread_mutex_lock(&philo->rules->mstop);
			philo->rules->stop = 1;
			pthread_mutex_unlock(&philo->rules->mstop);
			return (1);
		}
	}
	pthread_mutex_unlock(&philo->rules->mmeal);
	return (0);
}
