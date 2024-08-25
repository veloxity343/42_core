/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:28:27 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/25 11:33:09 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

enum e_bool
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

/*
@brief Structure to hold simulation data.
@param threads Pointer to an array of pthread_t representing philosopher threads.
@param forks Pointer to an array of pthread_mutex_t 
	representing forks as mutexes.
@param msg Pointer to a pthread_mutex_t for protecting message printing.
@param death Pointer to a pthread_mutex_t for death detection.
@param stop Pointer to a pthread_mutex_t to signal stopping the simulation.
@param start Start time of the simulation in milliseconds.
@param philo Number of philosophers.
@param time_to_die Time in milliseconds after which 
	a philosopher dies if not eating.
@param time_to_eat Time in milliseconds a philosopher spends eating.
@param time_to_sleep Time in milliseconds a philosopher spends sleeping.
@param eat_counter Counter for the number of times each philosopher has eaten.
@param max_eat Maximum times philosophers 
	should eat before ending the simulation.
@param is_dead Flag indicating if any philosopher has died.
@param current_eat Counter for the total number of 
	meals eaten by all philosophers.
*/
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

/*
@brief Structure to hold individual philosopher data.
@param eat Pointer to a pthread_mutex_t 
	representing the philosopher's eating mutex.
@param data Pointer to the simulation data structure.
@param eating_time Time in milliseconds when the philosopher starts eating.
@param next_meal Time in milliseconds when the philosopher should eat next.
@param index Index of the philosopher.
@param right_hand Index of the fork on the philosopher's right.
@param left_hand Index of the fork on the philosopher's left.
@param is_dead Flag indicating if the philosopher is dead.
@param eat_counter Counter for the number of times this philosopher has eaten.
*/
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
int				ft_data_param(t_sim *sim, int nbr, int i);
int				ft_set_data(t_sim *sim, int nbr, int i);
int				ft_check_last(t_sim *sim, int nbr, int i);
void			ft_destroy_all(t_sim *sim, t_philo *philo);
void			ft_iterate_philo(t_sim *sim, t_philo *philo,
					int i);
int				ft_error_put(t_sim *sim, char *msg, int ret);

#endif
