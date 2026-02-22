/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulescur <hulescur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:41:17 by hulescur          #+#    #+#             */
/*   Updated: 2026/02/21 15:33:01 by hulescur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str, int *error)
{
	int			i;
	int			s;
	long int	num;

	i = 0;
	s = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((s == 1 && num > 2147483647) || (s == -1 && num * s < -2147483648))
			*error = 1;
		i++;
	}
	if (str[i])
		*error = 1;
	return (num * s);
}
