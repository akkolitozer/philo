/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:16:42 by hulescur          #+#    #+#             */
/*   Updated: 2026/08/14 11:06:38 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start_routine(t_philo *philo)
{
	if (philo->rules->philo_number % 2 == 1)
	{
		if (philo->id == 2)
			usleep_hm(philo, philo->rules->time_to_eat * 1.5);
		else if (philo->id == 3)
			usleep_hm(philo, philo->rules->time_to_eat / 2);
		else if (philo->id % 2 == 0)
			usleep_hm(philo, philo->rules->time_to_eat * 2);
		else if (philo->id != 1)
			usleep_hm(philo, philo->rules->time_to_eat);
	}
	else if (philo->id % 2 == 0)
		usleep_hm(philo, philo->rules->time_to_eat / 2);
}
