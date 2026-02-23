/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:35:58 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/23 15:45:53 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	parser_args(t_data philos, int	data, int i)
{
	if (i == 1)
		philos.philo_numbers = data;
	if (i == 2)
		philos.time_to_die = data;
	if (i == 3)
		philos.time_to_eat = data;
	if (i == 4)
		philos.time_to_sleep = data;
	if (i == 5)
		philos.number_of_meals = data;
}