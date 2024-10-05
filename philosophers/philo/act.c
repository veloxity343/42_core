/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:28:17 by rcheong           #+#    #+#             */
/*   Updated: 2024/10/05 15:48:04 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
@brief Philosopher takes the necessary forks to eat.
@param philo Pointer to a philosopher structure (t_philo).
@details Locks the forks mutexes so the philosopher can eat.
*/
void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left_hand]);
	ft_print_msg(FORK, philo);
	pthread_mutex_lock(&philo->data->forks[philo->right_hand]);
	ft_print_msg(FORK, philo);
}

/*
@brief Handles the eating action of a philosopher.
@param philo Pointer to a philosopher structure (t_philo).
@details Updates the philosopher's next meal time and manages forks.
*/
void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->eat);
	ft_print_msg(EAT, philo);
	if (philo->data->eat_counter != -1)
		philo->data->current_eat++;
	philo->eating_time = ft_get_time();
	philo->next_meal = philo->eating_time
		+ (unsigned int)philo->data->time_to_die;
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->left_hand]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_hand]);
	pthread_mutex_unlock(philo->eat);
}

/*
@brief Handles the sleeping action of a philosopher.
@param philo Pointer to a philosopher structure (t_philo).
@details Puts the philosopher to sleep for the specified time.
*/
void	ft_sleep(t_philo *philo)
{
	usleep(10);
	ft_print_msg(SLEEP, philo);
	usleep(philo->data->time_to_sleep * 1000);
}

/*
@brief Get the current time in milliseconds.
@return Current time in milliseconds.
@details Retrieves the current time,
	typically used to time-stamp philosopher actions.
*/
unsigned int	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
