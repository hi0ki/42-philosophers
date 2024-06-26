/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:05:49 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/06/04 16:05:51 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <sys/time.h>

# define ERROR 0
# define GOOD 1

typedef struct s_data{
	sem_t			*var;
	sem_t			*dead;
	sem_t			*save;
	sem_t			*sem_meals;
	pthread_t		thread;
	bool			last_arg;
	int				*pids;
	int				id;
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_meals;
	long			last_meal;
	long			start_time;
}t_data;

/*				utils					*/
int		ft_atoi(char *str);
long	get_time(void);
int		my_usleep(long sleep_time, t_data *philo);
int		my_printf(char *s, t_data *philo);
/*				fill sturcts			*/
int		fill_struct(t_data *data, char **av);
/*				routine 				*/
void	routine(t_data *philo);
void	*check(void *param);

#endif
