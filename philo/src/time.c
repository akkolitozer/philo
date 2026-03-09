/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkolitozer <akkolitozer@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:18:59 by hulescur          #+#    #+#             */
/*   Updated: 2026/03/10 00:04:29 by akkolitozer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long    get_ms(void)
{
    struct timeval  tv;
    int             error;

    error = gettimeofday(&tv, NULL);
    if (error)
        return (0);
    return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void    usleep_hm(t_philo *philo)
{
    long    target;

    target = get_ms() + philo->rules->time_to_sleep;
    while (get_ms() < target && !philo->rules->stop)
        usleep(150);
}
