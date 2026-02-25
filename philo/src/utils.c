#include "../includes/philo.h"

int	ft_atoi(const char *str, t_rules *rules)
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
			rules->error = 1;
		i++;
	}
	if (str[i] || num * s <= 0)
		rules->error = 1;
	return (num * s);
}
