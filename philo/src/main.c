/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:22:40 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/24 01:26:42 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	int		error;
	t_rules	rules;

	if (ac == 5 || ac == 6)
		error = parser_args(&rules, av);
	else
		printf("Error\nWrong Arguments Number.\n");
	if (error)
		printf("Error\nInvalid Arguments\n");
	return (0);
}
