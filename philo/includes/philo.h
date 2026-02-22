/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:23:22 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/22 20:26:55 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_data
{
	int	philo_numbers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
}				t_data;

#endif