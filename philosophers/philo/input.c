/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:15 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/10 18:07:10 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Parses the input arguments provided to the program.
 * @details This function parses the input arguments,
 * converts them into integers, and stores them in the data structure.
 * It checks if the input is valid and ensures that
 * the number of philosophers is at least 1.
 * @param data Pointer to the shared data structure
 * where parsed input values will be stored.
 * @return Returns SUCCESS if parsing is successful,
 * otherwise returns ERROR if invalid input is encountered.
 */
static int	ft_parse_input(t_data *data)
{
	long	num;
	int		i;
	int		j;

	i = 0;
	while (++i < data->argc)
	{
		num = 0;
		j = -1;
		while (data->argv[i][++j] != '\0')
		{
			if (!(data->argv[i][j] >= '0' && data->argv[i][j] <= '9'))
				return (ft_print_error("Input must be positive integer only \
(without '+' sign)."));
			num = num * 10 + (data->argv[i][j] - '0');
		}
		data->input[i - 1] = num;
		if (data->input[0] == 0)
			return (ft_print_error("Number of philosophers \
must be at least 1."));
		if (i - 1 >= 1 && i - 1 <= 3)
			data->input[i - 1] *= 1000;
	}
	return (SUCCESS);
}

/**
 * @brief Creates a linked list of philosophers.
 * @details This function creates a circular doubly linked list
 * where each philosopher is represented as a node.
 * It also initializes the mutexes for each philosopher's fork and last eat lock.
 * @param data Pointer to the shared data structure containing input data.
 * @param temp Pointer to a philosopher node, used to build the linked list.
 * @return Returns SUCCESS if the linked list is created successfully,
 * otherwise returns ERROR if memory allocation or mutex initialization fails.
 */
static int	ft_create_linked_list(t_data *data, t_philo *temp)
{
	long	i;

	i = 0;
	while (++i <= data->input[NUM_OF_PHILOS])
	{
		temp->num = i;
		if (pthread_mutex_init(&temp->fork, NULL) != 0)
			return (ft_print_error(MUTEX_INIT));
		if (pthread_mutex_init(&temp->last_eat_lock, NULL) != 0)
			return (ft_print_error(MUTEX_INIT));
		temp->data = data;
		if (i == data->input[NUM_OF_PHILOS])
			break ;
		temp->next = (t_philo *)malloc(sizeof(t_philo));
		if (temp->next == NULL)
			return (ft_print_error(MALLOC));
		*(temp->next) = (t_philo){0};
		temp->next->prev = temp;
		temp = temp->next;
	}
	temp->next = data->first;
	data->first->prev = temp;
	data->last = temp;
	return (SUCCESS);
}

/**
 * @brief Processes the input parameters for the simulation.
 * @details This function validates the number of arguments and
 * parses the command-line inputs into the appropriate data structure.
 * It also initializes the mutex locks for synchronization between philosophers.
 * @param data Pointer to the shared data structure containing parsed input.
 * @return Returns SUCCESS if the inputs are processed successfully,
 * otherwise returns ERROR if any issues are encountered.
 */
int	ft_input(t_data *data)
{
	if (data->argc < 5 || data->argc > 6)
		return (ft_print_error(ARGC));
	if (ft_parse_input(data) == ERROR)
		return (ERROR);
	if (data->input[NUM_OF_TIMES_TO_EAT] != -1
		&& pthread_mutex_init(&data->all_full_lock, NULL) != 0)
		return (ft_print_error(MUTEX_INIT));
	data->first = (t_philo *)malloc(sizeof(t_philo));
	if (data->first == NULL)
		return (ft_print_error(MALLOC));
	*(data->first) = (t_philo){0};
	if (ft_create_linked_list(data, data->first) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
