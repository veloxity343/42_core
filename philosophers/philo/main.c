/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:29:10 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/16 11:34:16 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Main thread function for each philosopher subsequent thread.
 * @details This function is the entry point for each philosopher's thread,
 * handling the cycle of eating, sleeping, and thinking.
 * It ensures that the philosopher performs these actions
 * repeatedly until the program ends or an error occurs.
 * Delays for each even-numbered philosopher to prevent a deadlock.
 * @param func_arg The argument passed to the thread,
 * which is a pointer to a philosopher's struct.
 * @return Always returns NULL when the thread finishes execution.
 */
static void	*ft_thread_main(void *func_arg)
{
	t_philo	*thread;
	t_data	*data;
	int		full_flag;

	thread = func_arg;
	data = thread->data;
	full_flag = 0;
	if (thread->num % 2 == 0)
		ft_usleep(500);
	while (1)
	{
		if (ft_philo_eat(data, thread, &full_flag) == 1)
			return (NULL);
		if (ft_philo_sleep(data, thread) == 1)
			return (NULL);
		if (ft_philo_think(data, thread) == 1)
			return (NULL);
	}
}

/**
 * @brief Creates threads for each philosopher.
 * @details This function initializes a new thread for each philosopher
 * and sets their last eating time. It loops through all philosophers
 * and creates a corresponding thread for each.
 * @param data Pointer to the shared data structure
 * containing the list of philosophers.
 * @return Returns SUCCESS if all threads are created successfully,
 * otherwise returns ERROR if thread creation fails.
 */
static int	ft_create_threads(t_data *data)
{
	t_philo	*thread;

	thread = data->first;
	data->init_time = ft_get_curr_time();
	while (1)
	{
		thread->last_eat = ft_get_curr_time();
		if (pthread_create(&thread->tid, NULL, ft_thread_main, thread) != 0)
			ft_print_error(THREAD_CREATE);
		thread = thread->next;
		if (thread == data->first)
			break ;
	}
	return (SUCCESS);
}

/**
 * @brief Joins all philosopher threads.
 * @details This function waits for each philosopher's thread to finish.
 * It calls pthread_join for each thread in the
 * linked list (main thread) of philosophers.
 * @param data Pointer to the shared data structure
 * containing the list of philosophers.
 * @return No return value. The function blocks until all threads have completed.
 */
static void	ft_join_threads(t_data *data)
{
	t_philo	*thread;

	thread = data->first;
	while (1)
	{
		pthread_join(thread->tid, NULL);
		thread = thread->next;
		if (thread == data->first)
			break ;
	}
}

/**
 * @brief Manages the threading logic for the philosophers' simulation.
 * @details This function creates the philosopher threads and continuously checks
 * if all philosophers are full or if any philosopher has died.
 * It also handles the termination of threads and
 * ensures that no philosopher runs out of time.
 * @param data Pointer to the shared data structure
 * containing the philosophers and input data.
 * @return Returns SUCCESS if everything proceeds without error,
 * otherwise returns ERROR if any issue occurs.
 */
int	ft_threading(t_data *data)
{
	t_philo	*thread;

	if (data->input[NUM_OF_TIMES_TO_EAT] == 0)
	{
		printf("Success! All philosophers made it through \
without a single food fight.\n");
		return (SUCCESS);
	}
	if (ft_create_threads(data) == ERROR)
		return (ERROR);
	thread = data->first;
	while (1)
	{
		if (ft_check_last_eat(data, thread) == 1)
			break ;
		thread = thread->next;
		if (data->input[NUM_OF_TIMES_TO_EAT] != -1 && ft_check_full(data) == 1)
			break ;
	}
	ft_join_threads(data);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_print_error(MALLOC));
	*data = (t_data){0};
	if (ft_init_data(data, argc, argv) == ERROR)
		return (ERROR);
	if (ft_input(data) == ERROR)
		return (ERROR);
	if (ft_threading(data) == ERROR)
		return (ERROR);
	ft_clean(data);
	return (SUCCESS);
}
