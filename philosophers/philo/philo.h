/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:05 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/10 18:09:30 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/* MACROS */
# define ARGC "4 to 5 arguments needed.\n\
Usage: ./philo [0] [1] [2] [3] [4]\n\
[0]: number_of_philosophers\n\
[1]: time_to_die (in ms)\n\
[2]: time_to_eat (in ms)\n\
[3]: time_to_sleep (in ms)\n\
[4]: number_of_times_each_philosopher_must_eat (optional)"
# define MALLOC "Failed to allocate memory."
# define MUTEX_INIT "Failed to initialize mutex."
# define TIME "Failed to get time."
# define THREAD_CREATE "Failed to create thread."
# define MUTEX_DESTROY "Failed to destroy mutex."

/**
 * @brief Enum for exit statuses.
 * @param SUCCESS The operation was successful.
 * @param ERROR An error occurred during the operation.
 */
enum e_exitstatus
{
	SUCCESS,
	ERROR
};

/**
 * @brief Enum for input parameters.
 * @param NUM_OF_PHILOS The number of philosophers.
 * @param TIME_TO_DIE The time before a philosopher dies due to starvation.
 * @param TIME_TO_EAT The time a philosopher takes to eat.
 * @param TIME_TO_SLEEP The time a philosopher takes to sleep.
 * @param NUM_OF_TIMES_TO_EAT The number of times each philosopher needs to eat.
 */
enum e_input
{
	NUM_OF_PHILOS,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	NUM_OF_TIMES_TO_EAT
};

/**
 * @brief Enum for possible philosopher actions.
 * @param FORK The action of taking a fork.
 * @param EAT The action of eating.
 * @param SLEEP The action of sleeping.
 * @param THINK The action of thinking.
 */
enum e_actions
{
	FORK,
	EAT,
	SLEEP,
	THINK	
};

/**
 * @brief Struct to represent a philosopher.
 * @param tid The thread ID of the philosopher.
 * @param num The philosopher's number (ID).
 * @param fork The mutex for synchronizing access to the philosopher's fork.
 * @param num_eat The number of times the philosopher has eaten.
 * @param last_eat The timestamp of the philosopher's last meal.
 * @param last_eat_lock The mutex for synchronizing
 * access to the philosopher's last eating time.
 * @param next A pointer to the next philosopher in the linked list.
 * @param prev A pointer to the previous philosopher in the linked list.
 * @param data A pointer to the shared data structure.
 */
typedef struct s_philo
{
	pthread_t		tid;
	int				num;
	pthread_mutex_t	fork;
	int				num_eat;
	long			last_eat;
	pthread_mutex_t	last_eat_lock;
	struct s_philo	*next;
	struct s_philo	*prev;
	void			*data;
}	t_philo;

/**
 * @brief Struct to represent the shared data of the simulation.
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * @param input An array holding the parsed input values.
 * @param all_full The flag indicating whether all philosophers are full.
 * @param all_full_lock The mutex for synchronizing access to the all_full flag.
 * @param dead The flag indicating whether a philosopher has died.
 * @param dead_lock The mutex for synchronizing access to the dead flag.
 * @param init_time The initial timestamp when the simulation started.
 * @param output The mutex for synchronizing output.
 * @param first A pointer to the first philosopher in the linked list.
 * @param last A pointer to the last philosopher in the linked list.
 */
typedef struct s_data
{
	int				argc;
	char			**argv;
	long			input[5];
	int				all_full;
	pthread_mutex_t	all_full_lock;
	int				dead;
	pthread_mutex_t	dead_lock;
	long			init_time;
	pthread_mutex_t	output;
	t_philo			*first;
	t_philo			*last;
}	t_data;

// Input
int		ft_threading(t_data *data);
int		ft_input(t_data *data);

// Actions
int		ft_philo_eat(t_data *data, t_philo *thread, int *full_flag);
int		ft_philo_think(t_data *data, t_philo *thread);
int		ft_philo_sleep(t_data *data, t_philo *thread);

// Action Utils
int		ft_check_last_eat(t_data *data, t_philo *thread);
int		ft_check_full(t_data *data);
int		ft_exit_status(t_data *data);
int		ft_print_status(t_data *data, t_philo *thread, int num);
void	ft_usleep(long usec);
long	ft_get_curr_time(void);

// Utils
int		ft_print_error(char *str);
int		ft_init_data(t_data *data, int argc, char **argv);
void	ft_clean(t_data *data);

#endif
