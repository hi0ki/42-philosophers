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

#include "philo_bonus.h"

static void	wait_process(t_data *data, int status)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		waitpid(-1, &status, 0);
		if (status == 256)
		{
			i = 0;
			while (i < data->n_philo)
			{
				kill(data->pids[i], 9);
				i++;
			}
		}
		sem_post(data->dead);
		i++;
	}
}

static int	creat_process(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < data->n_philo)
	{
		data->pids[i] = fork();
		if (data->pids[i] == 0) 
		{
			data->id = i + 1;
			pthread_create(&data->thread, NULL, &check, data);
			routine(data);
			pthread_join(data->thread, NULL);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	wait_process(data, status);
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
		if (creat_process(&data) == GOOD)
		{
			free(data.pids);
			return (ERROR);
		}
	}
	return (GOOD);
}
