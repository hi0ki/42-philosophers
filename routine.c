#include "philo.h"

static void unlock_forks(t_philo *philo)
{
		pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

static int take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	if (my_printf("%ld %d has taken a fork\n", philo) == DEAD)
			return (unlock_forks(philo), DEAD);
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	if (my_printf("%ld %d has taken a fork\n", philo) == DEAD)
			return (unlock_forks(philo), DEAD);
	return (GOOD);
}

void *routine(void *param)
{
	t_philo *philo;

	philo = (t_philo *)param;
	if (philo->id % 2 == 0)
	{
		if (my_printf("%ld %d is sleeping\n", philo) == DEAD)
			return (NULL);
		my_usleep(philo->data->t_sleep, philo);
	}
	while(check_dead(philo) == GOOD && philo->n_meals != 0)
	{
		my_printf("%ld %d is thinking\n", philo);
		if (take_forks(philo) == DEAD)
			break;
		my_printf("%ld %d is eating\n", philo);
		philo->n_meals--;
		pthread_mutex_lock(&philo->data->save);
		philo->last_meal = get_time();
		pthread_mutex_unlock(&philo->data->save);
		my_usleep(philo->data->t_eat, philo);
		unlock_forks(philo);
		my_printf("%ld %d is sleeping\n", philo);
		my_usleep(philo->data->t_sleep, philo);
	}
	return NULL;
}
