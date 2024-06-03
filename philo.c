#include "philo.h"

void ll()
{
		system("leaks philo");
}

static int	main_check(t_data *data, int i)
{
	pthread_mutex_lock(&data->save);
	if (check_time(data, &data->philos[i]) == DEAD)
	{
		pthread_mutex_lock(&data->check);
		data->dead = false;
		pthread_mutex_unlock(&data->check);
		printf("\033[1;31m%ld %d is died\n", get_time() - data->start_time, data->philos[i].id);
		pthread_mutex_unlock(&data->save);
		return (DEAD);
	}
	pthread_mutex_unlock(&data->save);
	return (GOOD);
}

static int	create_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_philo)
	{
		fill_philo(data, &data->philos[i], i);
		pthread_create(&data->threads[i], NULL, routine, &data->philos[i]);
		i++;
	}
	i = 0;
	while (1)
	{
		if (i == data->n_philo)
			i = 0;
		if (main_check(data, i) == DEAD)
			break;
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->threads[i], NULL);
		i++;
	}
	return (GOOD);
}

int main(int ac, char **av)
{
	t_data	data;

	atexit(ll);
	if (ac == 5)
	{
		if (fill_struct(&data, av) == ERROR)
			return (ERROR);
		if (create_threads(&data) == ERROR)
			return (ERROR);
		destroy(&data);
		free(data.threads);
		free(data.forks);
		free(data.philos);
	}
}