/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:15:12 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/06/05 23:15:16 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*r_one_thread(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	pthread_mutex_lock(&data->forks[0]);
	printf("%ld 1 is taken fork\n", get_time() - data->start_time);
	pthread_mutex_unlock(&data->forks[0]);
	my_usleep(data->t_die, NULL);
	printf("%ld 1 is died\n", get_time() - data->start_time);
	return (NULL);
}

static int	one_thread(t_data *data)
{
	pthread_create(&data->threads[0], NULL, r_one_thread, data);
	pthread_join(data->threads[0], NULL);
	return (GOOD);
}

static int	main_check(t_data *data, int i)
{
	pthread_mutex_lock(&data->save);
	if (check_time(data, &data->philos[i]) == DEAD)
	{
		pthread_mutex_lock(&data->check);
		data->dead = false;
		pthread_mutex_unlock(&data->check);
		printf("\033[1;31m%ld %d is died\n",
			get_time() - data->start_time, data->philos[i].id);
		pthread_mutex_unlock(&data->save);
		return (DEAD);
	}
	else if (data->philos[i].n_meals == 0)
	{
		pthread_mutex_unlock(&data->save);
		return (DEAD);
	}
	pthread_mutex_unlock(&data->save);
	return (GOOD);
}

static int	create_threads(t_data *data)
{
	int	i;

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
			break ;
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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (ac == 6)
			data.last_arg = true;
		if (fill_struct(&data, av) == ERROR)
			return (ERROR);
		if (data.n_philo == 1)
			one_thread(&data);
		else
		{
			if (create_threads(&data) == ERROR)
				return (ERROR);
		}
		destroy(&data);
		free(data.threads);
		free(data.forks);
		free(data.philos);
	}
}
