/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:06:02 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/06/04 16:06:03 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	fill_struct(t_data *data, char **av)
{
	sem_unlink("/sema");
	sem_unlink("/dead");
	sem_unlink("/save");
	// sem_unlink("/meals");
	if (data->last_arg == true)
		data->n_meals = ft_atoi(av[5]);
	else
		data->n_meals = -1;
	data->start_time = get_time();
	data->last_meal = get_time();
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->var = malloc(data->n_philo * sizeof(sem_t));
	data->dead = malloc(data->n_philo * sizeof(sem_t));
	data->save	= malloc(data->n_philo * sizeof(sem_t));
	data->sem_meals =malloc(data->n_philo * sizeof(sem_t));
	int i = 0;
	while(i < data->n_philo)
	{
		data->dead[i] = sem_open("/dead", O_CREAT, 0777, 1);
		data->save[i] = sem_open("/save", O_CREAT, 0777, 1);
		data->sem_meals[i] = sem_open("/meals", O_CREAT, 0777, 1);
		i++;
	}
	data->var = sem_open("/sema", O_CREAT, 0777, data->n_philo);
	data->pids = malloc(data->n_philo * sizeof(int));
	if (data->n_philo > 200 || data->n_philo <= 0 || data->t_die < 60 || 
		data->t_eat < 60 || data->t_sleep < 60 || data->n_meals == 0)
		return (ERROR);
	return (GOOD);
}

/*

kill;

*/