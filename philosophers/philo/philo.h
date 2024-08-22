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

/* ENUMS */
enum e_status
{
	NO,
	YES
};

enum e_actions
{
	FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DIED,
	DONE
};

/* STRUCTS */
typedef struct s_sim
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*msg;
	pthread_mutex_t		*death;
	pthread_mutex_t		*stop;
	unsigned int		start;
	int					philo;
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

/* FUNCS */
unsigned int	ft_get_time(void);
void			*ft_routine(void *arg);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
int				ft_get_nbr(char *arg);
void			*ft_check_death(void *arg);
void			ft_take_fork(t_philo *philo);
void			ft_print_msg(int id, t_philo *philo);
t_philo			*ft_philo_init(t_sim *sim);
void			ft_create_mutex(t_sim *sim);
int				ft_parse(char **argv, t_sim *sim);
int				ft_set_rest(t_sim *sim, int nbr, int i);
int				ft_set_data(t_sim *sim, int nbr, int i);
int				ft_check_last(t_sim *sim, int nbr, int i);
void			ft_destroy_all(t_sim *sim, t_philo *philo);
void			ft_for_each_philo(t_sim *sim, t_philo *philo,
					int i);
int				ft_error_put(t_sim *sim, char *msg, int ret);

#endif
