/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:06:07 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/06/04 16:06:13 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	long			time;
	struct timeval	s_tm;

	gettimeofday(&s_tm, NULL);
	time = s_tm.tv_sec * 1000 + s_tm.tv_usec / 1000;
	return (time);
}

int	my_usleep(long sleep_time, t_data *philo)
{
	long	start;

	(void)philo;
	start = get_time();
	while (get_time() - start < sleep_time)
	{
		usleep(1000);
	}
	return (GOOD);
}

int	my_printf(char *s, t_data *philo)
{
	// sem_wait(philo->dead);
	printf(s, get_time() - philo->start_time, philo->id);
	// sem_post(philo->dead);
	return (GOOD);
}

// int	check_dead(t_philo *philo)
// {
// 	if (philo == NULL)
// 		return (true);
// 	pthread_mutex_lock(&philo->data->check);
// 	if (philo->data->dead == false)
// 	{
// 		pthread_mutex_unlock(&philo->data->check);
// 		return (DEAD);
// 	}
// 	pthread_mutex_unlock(&philo->data->check);
// 	return (GOOD);
// }

// int	check_time(t_data *data, t_philo *philo)
// {
// 	if (get_time() - philo->last_meal >= data->t_die)
// 		return (DEAD);
// 	return (GOOD);
// }