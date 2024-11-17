/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:22 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/17 12:50:26 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Gets the current time in microseconds.
 * @details This function fetches the current time using
 * `gettimeofday` and returns it in microseconds.
 * @param None.
 * @return The current time in microseconds.
 */
long	ft_get_curr_time(void)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL) == -1)
		ft_print_error(TIME);
	return ((curr_time.tv_sec * 1000000) + curr_time.tv_usec);
}

/**
 * @brief Sleeps for the specified amount of time
 * with microsecond precision.
 * @details This function makes the program sleep
 * for the specified amount of microseconds,
 * adjusting the sleep duration based on the remaining time.
 * @param usec The number of microseconds to sleep.
 */
void	ft_usleep(long usec)
{
	long	start;
	long	diff;

	start = ft_get_curr_time();
	while (1)
	{
		diff = usec - (ft_get_curr_time() - start);
		if (diff <= 0)
			break ;
		if (diff > 10000)
			usleep(diff / 2);
		else
			usleep(500);
	}
}

/**
 * @brief Checks if a philosopher has exceeded their
 * last eat time and should die.
 * @details This function compares the time since the philosopher's
 * last meal to the time_to_die parameter.
 * If the philosopher has died, it sets the
 * dead flag and prints the death message.
 * @param data Pointer to the main
 * data structure holding program state.
 * @param thread Pointer to the philosopher's struct,
 * representing the current philosopher.
 * @return 1 if the philosopher is dead, 0 otherwise.
 */
int	ft_check_last_eat(t_data *data, t_philo *thread)
{
	long	time_since;
	long	diff;

	pthread_mutex_lock(&thread->last_eat_lock);
	diff = ft_get_curr_time() - thread->last_eat;
	pthread_mutex_unlock(&thread->last_eat_lock);
	if (diff > data->input[TIME_TO_DIE])
	{
		pthread_mutex_lock(&data->dead_lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_lock);
		ft_usleep(1000);
		time_since = (ft_get_curr_time() - data->init_time) / 1000;
		printf("%ld %d died\n", time_since, thread->num);
		return (1);
	}
	return (0);
}

/**
 * @brief Checks if all philosophers are full.
 * @details This function checks if the `all_full` counter
 * has reached the number of philosophers.
 * If all are full, it prints a message and returns 1.
 * @param data Pointer to the main data structure holding program state.
 * @return 1 if all philosophers are full, 0 otherwise.
 */
int	ft_check_full(t_data *data)
{
	pthread_mutex_lock(&data->all_full_lock);
	if (data->all_full == (int)data->input[NUM_OF_PHILOS])
	{
		pthread_mutex_unlock(&data->all_full_lock);
		ft_usleep(1000);
		printf("Success! All philosophers made it through \
without a single food fight.\n");
		return (1);
	}
	pthread_mutex_unlock(&data->all_full_lock);
	return (0);
}

/**
 * @brief Prints the status of a philosopher's action.
 * @details This function prints the status message
 * based on the philosopher's action, such as taking a fork, eating, sleeping,
 * or thinking, along with the time elapsed since the start of the simulation.
 * @param data Pointer to the main data structure holding program state.
 * @param thread Pointer to the philosopher's struct,
 * representing the current philosopher.
 * @param num The action number (FORK, EAT, SLEEP, THINK).
 * @return 1 if printing fails, 0 otherwise.
 */
int	ft_print_status(t_data *data, t_philo *thread, int num)
{
	long	time_since;

	if (ft_exit_status(data) == 1)
		return (1);
	pthread_mutex_lock(&data->output);
	time_since = (ft_get_curr_time() - data->init_time) / 1000;
	if (num == FORK)
		printf("%ld %d has taken a fork\n", time_since, thread->num);
	else if (num == EAT)
		printf("%ld %d is eating\n", time_since, thread->num);
	else if (num == SLEEP)
		printf("%ld %d is sleeping\n", time_since, thread->num);
	else if (num == THINK)
		printf("%ld %d is thinking\n", time_since, thread->num);
	pthread_mutex_unlock(&data->output);
	return (0);
}
