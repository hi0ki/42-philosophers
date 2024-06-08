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


/*
		onzid id f struct dyali
		ghadi nforki o child nsifthom nichan l routine 
		o semaphore andirha lforks
		o mora fach ndir hadchi ndir thread lkola child bach njrb wach mat ola mat ndir wahd variable dyal symaphore bach n3rf rah mat
*/

static int	create_threads(t_data *data)
{
	// int	i;
	// int	pid;

	(void)data;
	// i = 0;
	// while (i < data->n_philo)
	// {
		fork();
		printf("mehdi\n");
		fork();
		printf("mehdi\n");
	// 	i++;
	// }
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
		create_threads(&data);
	}
}
