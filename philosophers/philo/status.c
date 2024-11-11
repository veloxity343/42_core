/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:29 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/10 18:00:27 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if a philosopher should exit
 * due to death or if all philosophers are full.
 * @details This function checks the global dead flag or
 * checks if all philosophers have eaten the required times
 * to stop the simulation.
 * @param data Pointer to the main data structure holding program state.
 * @return 1 if the simulation should exit, 0 otherwise.
 */
int	ft_exit_status(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->dead_lock);
	if (data->input[NUM_OF_TIMES_TO_EAT] == -1)
		return (0);
	pthread_mutex_lock(&data->all_full_lock);
	if (data->all_full == (int)data->input[0])
	{
		pthread_mutex_unlock(&data->all_full_lock);
		return (1);
	}
	pthread_mutex_unlock(&data->all_full_lock);
	return (0);
}
