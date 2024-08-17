#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

enum e_exitstatus
{
	SUCCESS,
	ERROR
};

enum e_actions
{
	FORK,
	EAT,
	SLEEP,
	THINK	
};

typedef struct s_sim
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*msg;
	pthread_mutex_t		*death;
	pthread_mutex_t		*stop;
	unsigned int		start;
	int					philo_id;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_counter;
	int					max_eat;
	int					is_dead;
	int					current_eat;
}				t_sim;

typedef struct s_philo
{
	pthread_mutex_t	*eat;
	t_sim			*data;
	unsigned int	eating_time;
	unsigned int	next_meal;
	int				index;
	int				right_hand;
	int				left_hand;
	int				is_dead;
	int				eat_counter;
}				t_philo;



#endif
