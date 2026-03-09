/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:22:40 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/09 23:39:24 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_rules	*rules;
	t_philo	*philo;
	
	rules = ft_calloc(1, sizeof(t_rules));
	if (ac == 5 || ac == 6)
		parser_args(rules, av);
	else
		return (printf("Error\nWrong Arguments Number.\n"));
	philo = ft_calloc(rules->philo_number, sizeof(t_philo));
	if (rules->error)
		return (1);
	rules->start = get_ms();
	if (init_philos(&philo, rules))
		return (printf("Error\nFailed philo init\n"));
	return (0);
}
