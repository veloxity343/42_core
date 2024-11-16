/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:18 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/16 11:30:45 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Locks the fork for the philosopher and prints the action status.
 * @details This function locks the current philosopher's fork,
 * prints the "has taken a fork" status, and checks if there's only
 * one philosopher, in which case the philosopher dies after a specified time.
 * @param data Pointer to the main data structure holding program state.
 * @param thread Pointer to the philosopher's struct,
 * representing the current philosopher.
 */
static void	ft_take_fork(t_data *data, t_philo *thread)
{
	pthread_mutex_lock(&thread->fork);
	ft_print_status(data, thread, FORK);
	if (data->input[NUM_OF_PHILOS] == 1)
	{
		ft_usleep(data->input[TIME_TO_DIE]);
		return ;
	}
	pthread_mutex_lock(&thread->next->fork);
	ft_print_status(data, thread, FORK);
}

/**
 * @brief Unlocks the fork after the philosopher is done using it.
 * @details This function unlocks the current philosopher's fork
 * and the next philosopher's fork. If only one philosopher is present,
 * it skips unlocking the next fork.
 * @param data Pointer to the main data structure holding program state.
 * @param thread Pointer to the philosopher's struct,
 * representing the current philosopher.
 */
static void	ft_put_fork(t_data *data, t_philo *thread)
{
	pthread_mutex_unlock(&thread->fork);
	if (data->input[NUM_OF_PHILOS] == 1)
		return ;
	pthread_mutex_unlock(&thread->next->fork);
}

/**
 * @brief Simulates a philosopher thinking.
 * @details This function triggers the "thinking" status
 * and checks if printing the status was successful.
 * @param data Pointer to the main data structure holding program state.
 * @param thread Pointer to the philosopher's struct,
 * representing the current philosopher.
 * @return 1 if printing fails, 0 otherwise.
 */
int	ft_philo_think(t_data *data, t_philo *thread)
{
	if (ft_print_status(data, thread, THINK) == 1)
		return (1);
	return (0);
}

/**
 * @brief Simulates a philosopher sleeping.
 * @details This function triggers the "sleeping" status
 * and then makes the philosopher sleep for the specified time.
 * @param data Pointer to the main data structure holding program state.
 * @param thread Pointer to the philosopher's struct,
 * representing the current philosopher.
 * @return 1 if printing the status fails, 0 otherwise.
 */
int	ft_philo_sleep(t_data *data, t_philo *thread)
{
	if (ft_print_status(data, thread, SLEEP) == 1)
		return (1);
	ft_usleep(data->input[TIME_TO_SLEEP]);
	return (0);
}

/**
 * @brief Simulates a philosopher eating.
 * @details This function handles the process of a philosopher taking forks,
 * eating, updating their state and last eat, and putting the forks back.
 * It also tracks how many times the philosopher has eaten
 * and updates the global full flag.
 * @param data Pointer to the main data structure holding program state.
 * @param thread Pointer to the philosopher's struct,
 * representing the current philosopher.
 * @param full_flag A pointer to the full flag,
 * indicating whether all philosophers are full.
 * @return 1 if eating status printing fails, 0 otherwise.
 */
int	ft_philo_eat(t_data *data, t_philo *thread, int *full_flag)
{
	ft_take_fork(data, thread);
	if (ft_print_status(data, thread, EAT) == 1)
	{
		ft_put_fork(data, thread);
		return (1);
	}
	pthread_mutex_lock(&thread->last_eat_lock);
	thread->last_eat = ft_get_curr_time();
	pthread_mutex_unlock(&thread->last_eat_lock);
	ft_usleep(data->input[TIME_TO_EAT]);
	thread->num_eat++;
	if (data->input[NUM_OF_TIMES_TO_EAT] != -1 && *full_flag == 0
		&& thread->num_eat == (int)data->input[NUM_OF_TIMES_TO_EAT])
	{
		pthread_mutex_lock(&data->all_full_lock);
		data->all_full++;
		pthread_mutex_unlock(&data->all_full_lock);
		*full_flag = 1;
	}
	ft_put_fork(data, thread);
	return (0);
}
