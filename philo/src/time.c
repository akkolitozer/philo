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

void    usleep_hm(long duration, t_rules *rules)
{
    long    target;

    target = get_ms() + duration;
    while (get_ms() < target && !rules->stop)
    {
        if ((target - get_ms()) > 2)
            usleep(1000);
        else
            usleep(150);
    }
}
