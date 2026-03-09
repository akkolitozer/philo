/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:23:22 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/10 00:06:41 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct		s_rules
{
	int				philo_number;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_meals;
	long			start;
	long			now;
	int				stop;
	int				error;
	pthread_mutex_t	*forks;
}					t_rules;

typedef struct	s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			meals_eaten;
	long		last_meal;
	t_rules		*rules;
	pthread_t	thread;
}				t_philo;

long    get_ms(void);
void	*routine(void *arg);
void	ft_putstr(char *str);
void    usleep_hm(t_philo *philo);
void	*ft_calloc(size_t count, size_t size);
void	parser_args(t_rules *rules, char **av);
int		ft_atoi(const char *str, t_rules *rules);
int		init_forks(t_philo **philo, t_rules *rules);
int		init_philos(t_philo **philo, t_rules *rules);

#endif
