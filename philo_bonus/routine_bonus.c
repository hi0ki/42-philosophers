/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:05:54 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/06/04 16:05:56 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	take_forks(t_data *philo)
{
	sem_wait(philo->var);
	my_printf("%ld %d has taken a fork\n", philo);
	sem_wait(philo->var);
	my_printf("%ld %d has taken a fork\n", philo);
}

static void	unlock_forks(t_data *philo)
{
	sem_post(philo->var);
	sem_post(philo->var);
}

void	*check(void *param)
{
	int		i;
	long	time;
	t_data	*philo;

	philo = (t_data *)param;
	i = 0;
	while (1)
	{
		sem_wait(philo->save);
		time = get_time() - philo->last_meal;
		sem_post(philo->save);
		if (time >= philo->t_die)
		{
			sem_wait(philo->dead);
			printf("\033[1;31m%ld %d is died\n", get_time() - philo->start_time, 
				philo->id);
			exit(EXIT_FAILURE);
		}
		sem_wait(philo->sem_meals);
		if (philo->n_meals == 0)
			break ;
		sem_post(philo->sem_meals);
		usleep(50);
	}
	return (NULL);
}

void	routine(t_data *philo)
{
	if (philo->id % 2 == 0)
	{
		my_printf("%ld %d is sleeping\n", philo);
		my_usleep(philo->t_sleep, philo);
	}
	while (philo->n_meals != 0)
	{
		my_printf("%ld %d is thinking\n", philo);
		take_forks(philo);
		my_printf("%ld %d is eating\n", philo);
		sem_wait(philo->save);
		philo->last_meal = get_time();
		sem_post(philo->save);
		my_usleep(philo->t_eat, philo);
		sem_wait(philo->sem_meals);
		philo->n_meals--;
		sem_post(philo->sem_meals);
		unlock_forks(philo);
		my_printf("%ld %d is sleeping\n", philo);
		my_usleep(philo->t_sleep, philo);
	}
	free(philo->pids);
}
