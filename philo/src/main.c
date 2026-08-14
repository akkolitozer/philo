/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:22:40 by hulescur          #+#    #+#             */
/*   Updated: 2026/08/14 10:58:05 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_rules	*rules;
	t_philo	*philo;
	int		i;

	i = -1;
	if (ac != 5 && ac != 6)
		return (printf("Error with argument number\n"));
	rules = ft_calloc(1, sizeof(t_rules));
	if (!rules)
		return (printf("Error creating rules struct\n"));
	parser_args(rules, av);
	if (rules->philo_number == 1)
		return (one_philo(rules), free(rules), 1);
	if (rules->error)
		return (free(rules), 1);
	philo = ft_calloc(rules->philo_number, sizeof(t_philo));
	if (!philo)
		return (free(rules), printf("Error creating philos struct\n"));
	if (init_philos(&philo, rules))
		return (free(rules), free(philo), printf("Error init philo\n"));
	monitor(philo);
	while (++i < rules->philo_number)
		pthread_join(philo[i].thread, NULL);
	destroy_mutexs(philo);
	return (0);
}
