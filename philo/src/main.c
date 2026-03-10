/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:22:40 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/10 01:46:21 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_rules	*rules;
	t_philo	*philo;
	int	i;
	
	i = -1;
	rules = ft_calloc(1, sizeof(t_rules));
	if (!rules)
		return (printf("Error creating rules struct\n"));
	if (ac == 5 || ac == 6)
		parser_args(rules, av);
	else
		return (printf("Error\nWrong Arguments Number.\n"));
	if (rules->error)
		return (1);
	philo = ft_calloc(rules->philo_number, sizeof(t_philo));
	if (!philo)
		return (printf("Error creating philos struct\n"));
	rules->start = get_ms();
	if (init_philos(&philo, rules))
		return (printf("Error\nFailed philo init\n"));
	monitor(philo);
	while (++i < rules->philo_number)
		pthread_join(philo[i].thread, NULL);
	destroy_mutexs(rules);
	return (0);
}
