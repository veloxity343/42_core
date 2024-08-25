/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:28:25 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/25 11:43:22 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
@brief Checks if the philosopher has died.
@param arg: Pointer to the philosopher's structure.
@return NULL
@details Continuously monitors the philosopher's time until the next meal. 
	If the philosopher's time runs out, 
		marks them as dead and prints the death message.
*/
void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->next_meal < ft_get_time())
		{
			philo->data->is_dead = YES;
			pthread_mutex_lock(philo->eat);
			ft_print_msg(DIED, philo);
			pthread_mutex_unlock(philo->data->stop);
			break ;
		}
	}
	return (NULL);
}

/*
@brief Checks if all philosophers have eaten the required number of times.
@param philo: Pointer to the philosopher's structure.
@return 1 if eating continues, 0 if all philosophers are done eating.
@details Verifies if the maximum eating count is reached. 
	If yes, it marks the simulation as complete.
*/
int	ft_check_eat(t_philo *philo)
{
	if ((philo->data->eat_counter != -1)
		&& (philo->data->current_eat >= philo->data->max_eat))
	{
		philo->data->is_dead = YES;
		pthread_mutex_lock(philo->eat);
		ft_print_msg(DONE, philo);
		pthread_mutex_unlock(philo->data->stop);
		return (0);
	}
	return (1);
}

/*
@brief Maintais routine for each philosopher thread.
@param arg: Pointer to the philosopher's structure.
@return NULL
@details Executes and maintains the cycle of 
	taking forks, eating, sleeping, and thinking. 
	Spawns a thread to monitor the philosopher's death.
*/
void	*ft_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death;

	philo = arg;
	philo->next_meal = ft_get_time() + (unsigned int)philo->data->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detach(death);
	while (1)
	{
		if (philo->data->is_dead)
			break ;
		ft_take_fork(philo);
		ft_eat(philo);
		if (!ft_check_eat(philo))
			break ;
		ft_sleep(philo);
		ft_print_msg(THINK, philo);
	}
	return (NULL);
}

/*
@brief Prints an error message and frees resources.
@param sim: Pointer to the simulation structure.
@param msg: The error message to print.
@param ret: The return value to pass back.
@return The provided return value (ret).
@details Cleans up allocated resources if an error occurs during initialisation.
*/
int	ft_error_put(t_sim *sim, char *msg, int ret)
{
	if (sim)
	{
		if (sim->threads)
			free(sim->threads);
		if (sim->forks)
			free(sim->forks);
	}
	printf("%s\n", msg);
	return (ret);
}

/*
@brief Initialises the simulation, creates philosopher threads, 
	and manages their lifecycle.
@return 0 on successful execution, error code on failure.
*/
int	main(int argc, char **argv)
{
	int		i;
	t_sim	sim;
	t_philo	*philo;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (ft_parse(argv, &sim))
			return (0);
		philo = ft_philo_init(&sim);
		sim.start = ft_get_time();
		ft_create_mutex(&sim);
		pthread_mutex_lock(sim.stop);
		while (i < sim.philo)
		{
			pthread_create(sim.threads + i, NULL, ft_routine, philo + i);
			pthread_detach(sim.threads[i++]);
			usleep(100);
		}
		pthread_mutex_lock(sim.stop);
		ft_destroy_all(&sim, philo);
	}
	else
		printf("Error: 4 to 5 arguments needed\n");
	return (0);
}
