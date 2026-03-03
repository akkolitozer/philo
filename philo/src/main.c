/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:22:40 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/03 16:03:31 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_rules	*rules;
	t_philo	*philo;
	int		i;

	i = 0;
	if (ac == 5 || ac == 6)
		parser_args(rules, av);
	else
		return (printf("Error\nWrong Arguments Number.\n"));
	if (rules->error)
		return (1);
	if (!init_philos())
	rules->start = get_ms();
	go_routine(philo);
	return (0);
}
