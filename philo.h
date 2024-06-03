#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <sys/time.h>

#define DEAD -1
#define	ERROR 0
#define	GOOD 1

typedef struct s_data t_data;

typedef struct s_philo{
	int		id;
	int 	r_fork;
	int		l_fork;
	long	last_meal;
	t_data	*data;
}t_philo;

typedef struct s_data{
	pthread_t		*threads;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	check;
	pthread_mutex_t	save;
	t_philo			*philos;
	bool			dead;
	int 			n_philo;
	int 			t_die;
	int				t_eat;
	int 			t_sleep;
	long			start_time;
}t_data;

/*				utils					*/
int	ft_atoi(char *str);
long get_time();
int check_dead(t_philo *philo);
int	my_usleep(long sleep_time, t_philo *philo);
int my_printf(char *s, t_philo *philo);
int check_time(t_data *data, t_philo *philo);
/*				fill sturcts			*/
int		fill_struct(t_data *data, char **av);
void	fill_philo(t_data *data, t_philo *philo, int i);
void 	destroy(t_data *data);
/*				routine 				*/
void *routine(void *param);


#endif