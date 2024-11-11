/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:33 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/10 18:00:04 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints an error message to the standard error output.
 * @details This function outputs a formatted error message
 * to STDERR with the prefix "Error: ". 
 * It then prints the string provided as the argument followed by a newline.
 * @param str The error message to print.
 * @return Returns 1 to indicate an error occurred.
 */
int	ft_print_error(char *str)
{
	int	i;

	write(STDERR_FILENO, "Error: ", 7);
	i = -1;
	while (str[++i] != '\0')
		;
	write(STDERR_FILENO, str, i);
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

/**
 * @brief Initializes the data structure for the simulation.
 * @details This function sets the command-line arguments,
 * initializes the mutexes used in the simulation (dead_lock, output),
 * and sets the input array to -1 as a default value.
 * It also checks for errors during the initialization process.
 * @param data A pointer to the shared data structure
 * where the simulation data is stored.
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return Returns 0 if initialization is successful,
 * or calls `print_error` if a mutex initialization fails.
 */
int	ft_init_data(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	data->argc = argc;
	data->argv = argv;
	while (i < 5)
	{
		data->input[i] = -1;
		i++;
	}
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
		return (ft_print_error(MUTEX_INIT));
	if (pthread_mutex_init(&data->output, NULL) != 0)
		return (ft_print_error(MUTEX_INIT));
	return (0);
}

/**
 * @brief Frees the resources allocated for the simulation.
 * @details This function frees the memory allocated for
 * the philosopher linked list, destroys all mutexes,
 * and frees the main data structure.
 * It also checks for errors during the mutex destruction process.
 * @param data A pointer to the shared data structure
 * containing the simulation data and philosopher list.
 * @return No return value. The function cleans up resources and exits.
 */
void	ft_clean(t_data *data)
{
	t_philo	*temp;

	temp = data->first;
	while (1)
	{
		if (pthread_mutex_destroy(&temp->fork) != 0)
			ft_print_error(MUTEX_DESTROY);
		if (pthread_mutex_destroy(&temp->last_eat_lock) != 0)
			ft_print_error(MUTEX_DESTROY);
		if (temp == data->last)
			break ;
		temp = temp->next;
		free(temp->prev);
	}
	free(data->last);
	if (pthread_mutex_destroy(&data->dead_lock) != 0)
		ft_print_error(MUTEX_DESTROY);
	if (data->input[NUM_OF_TIMES_TO_EAT] != -1
		&& pthread_mutex_destroy(&data->all_full_lock) != 0)
		ft_print_error(MUTEX_DESTROY);
	if (pthread_mutex_destroy(&data->output) != 0)
		ft_print_error(MUTEX_DESTROY);
	free(data);
}
