#include "philo.h"

long get_time()
{
	long			time;
	struct timeval	s_tm;

	gettimeofday(&s_tm, NULL);
	time = s_tm.tv_sec * 1000 + s_tm.tv_usec / 1000;
	return (time);
}

int	my_usleep(long sleep_time, t_philo *philo)
{
	long	start;

	start = get_time();
	while (get_time() - start < sleep_time && check_dead(philo) == true)
	{
		usleep(42);
	}
	return (GOOD);
}

int my_printf(char *s, t_philo *philo)
{
	if (check_dead(philo) == false)
		return (DEAD);
	pthread_mutex_lock(&philo->data->print_lock);
	if (check_dead(philo) == true)
		printf(s, get_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_lock);
	return (GOOD);
}

int check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->check);
	if (philo->data->dead == false)
	{
		pthread_mutex_unlock(&philo->data->check);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->data->check);
	return (GOOD);
}