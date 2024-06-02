#include "philo.h"

int	fill_struct(t_data *data, char **av)
{
	int i;

	data->start_time = get_time();
	data->dead = true;
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (data->n_philo == 0 || data->t_die == 0 || 
		data->t_eat == 0 || data->t_sleep == 0)
		return (ERROR);
	data->threads = malloc(data->n_philo * sizeof(pthread_t));
	data->philos = malloc(data->n_philo * sizeof(t_data));
	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->check, NULL);
	pthread_mutex_init(&data->save, NULL);
	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (GOOD);
}

void	fill_philo(t_data *data, t_philo *philo, int i)
{
	philo->data = data;
	philo->id = i + 1;
	if (i != data->n_philo - 1)
	{
		philo->l_fork = i;
		philo->r_fork = i + 1;
	}
	else if (i == data->n_philo - 1)
	{
		philo->l_fork = i;
		philo->r_fork = 0;
	}
	philo->last_meal = get_time();
}