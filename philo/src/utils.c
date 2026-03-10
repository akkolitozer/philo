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

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	if (size && total_size / size != count)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	printff(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->rules->mwrite);
	printf("%ld %d %s\n", get_ms() - philo->rules->start, philo->id, str);
	pthread_mutex_unlock(&philo->rules->mwrite);
}