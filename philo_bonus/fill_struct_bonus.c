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
	if (data->last_arg == true)
		data->n_meals = ft_atoi(av[5]);
	else
		data->n_meals = -1;
	// data->start_time = get_time();
	data->dead = true;
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (data->n_philo > 200 || data->n_philo <= 0 || data->t_die < 60 || 
		data->t_eat < 60 || data->t_sleep < 60 || data->n_meals == 0)
		return (ERROR);
	return (GOOD);
}

// void	fill_philo(t_data *data, t_philo *philo, int i)
// {
// 	philo->data = data;
// 	philo->id = i + 1;
// 	philo->n_meals = data->n_meals;
// 	if (i != data->n_philo - 1)
// 	{
// 		philo->l_fork = i;
// 		philo->r_fork = i + 1;
// 	}
// 	else if (i == data->n_philo - 1)
// 	{
// 		philo->l_fork = i;
// 		philo->r_fork = 0;
// 	}
// 	philo->last_meal = get_time();
// }
