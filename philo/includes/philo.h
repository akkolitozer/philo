/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:23:22 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/24 01:25:09 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct s_rules
{
	int		philo_numbers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_meals;
	long	start;
	long	now;
	int		stop;
	int		error;
}				t_rules;

typedef struct s_philo
{
	int		id;
	long	last_meal;
	t_rules	*philos;

}				t_philo;

void	parser_args(t_rules *rules, char **av);
int		ft_atoi(const char *str, t_rules *rules);
long    get_ms(void);
void    usleep_hm(long duration, t_rules *rules);

#endif
