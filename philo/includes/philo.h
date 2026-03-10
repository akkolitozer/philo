/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:23:22 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/10 12:47:44 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_rules
{
	int				philo_number;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_of_meals;
	long			start;
	int				stop;
	int				error;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mstop;
	pthread_mutex_t	mwrite;
	pthread_mutex_t	mmeal;
}				t_rules;

typedef struct s_philo
{
	int			id;
	int			left_fork;
	int			right_fork;
	int			meals_eaten;
	long		last_meal;
	t_rules		*rules;
	pthread_t	thread;
}				t_philo;

long	get_ms(void);
void	eat(t_philo *philo);
void	*routine(void *arg);
void	ft_putstr(char *str);
void	monitor(t_philo *philo);
int		simstop(t_philo *philo);
void	dropfork(t_philo *philo);
void	takefork(t_philo *philo);
int		init_mutexs(t_rules *rules);
void	destroy_mutexs(t_rules *rules);
int		all_meals_eaten(t_philo *philo);
void	printfm(t_philo *philo, char *str);
void	*ft_calloc(size_t count, size_t size);
void	parser_args(t_rules *rules, char **av);
void	usleep_hm(t_philo *philo, int duration);
int		ft_atoi(const char *str, t_rules *rules);
int		init_forks(t_philo **philo, t_rules *rules);
int		init_philos(t_philo **philo, t_rules *rules);

#endif
