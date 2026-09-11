/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:16:42 by hulescur          #+#    #+#             */
/*   Updated: 2026/09/11 15:38:27 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_routine(t_philo *philo)
{
	if (philo->rules->philo_number % 2 == 1)
	{
		if (philo->id == 2)
			usleep_hm(philo, philo->rules->tte * 1.5);
		else if (philo->id == 3)
			usleep_hm(philo, philo->rules->tte / 2);
		else if (philo->id % 2 == 0)
			usleep_hm(philo, philo->rules->tte * 2);
		else if (philo->id != 1)
			usleep_hm(philo, philo->rules->tte);
	}
	else if (philo->id % 2 == 0)
		usleep_hm(philo, philo->rules->tte / 2);
}

void	announce_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->mwrite);
	pthread_mutex_lock(&philo->rules->mstop);
	philo->rules->stop = 1;
	printf("%ld %d died\n", get_ms() - philo->rules->start, philo->id);
	pthread_mutex_unlock(&philo->rules->mstop);
	pthread_mutex_unlock(&philo->rules->mwrite);
}
