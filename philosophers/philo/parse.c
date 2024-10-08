/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:28:22 by rcheong           #+#    #+#             */
/*   Updated: 2024/08/25 12:01:57 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
@brief Check for optional fifth argument.
@param sim Pointer to the simulation structure (t_sim).
@param nbr Value of argument.
@param i Argument type.
@return 0 on success, non-zero on failure.
@details Verifies if fifth argument is provided, 
	if so, set to value as eating needed to survive.
*/
int	ft_check_last(t_sim *sim, int nbr, int i)
{
	if (i == 5)
	{
		if (nbr == 0)
		{
			sim->eat_counter = -1;
			sim->current_eat = -1;
			sim->max_eat = -1;
		}
		else
		{
			sim->eat_counter = nbr;
			sim->current_eat = 0;
			sim->max_eat = nbr * sim->philo;
		}
		sim->is_dead = NO;
	}
	return (0);
}

/*
@brief Set simulation parameters time_to_eat and _sleep.
@param sim Pointer to the simulation structure (t_sim).
@param nbr Value of argument.
@param i Argument type.
@return 0 on success, non-zero on failure.
@details Configures remaining simulation settings 
	after parsing: time_to_eat and _sleep.
*/
int	ft_data_param(t_sim *sim, int nbr, int i)
{
	if (i == 3)
	{
		sim->time_to_eat = nbr;
	}
	else if (i == 4)
	{
		sim->time_to_sleep = nbr;
	}
	else
		ft_check_last(sim, nbr, i);
	return (0);
}

/*
@brief Set simulation paramenters philos, forks and time_to_die.
@param sim Pointer to the simulation structure (t_sim).
@param nbr Value of argument.
@param i Argument type.
@return 0 on success, non-zero on failure.
@details Initialises the first two simulation parameters: 
	counters for philosophers and forks and time_to_die.
*/
int	ft_set_data(t_sim *sim, int nbr, int i)
{
	if (i == 1)
	{
		if (nbr == 0)
			return (ft_error_put(NULL,
					"Error: Must have philosophers", 1));
		sim->philo = nbr;
		sim->threads = malloc(sizeof(pthread_t) * nbr);
		sim->forks = malloc(sizeof(pthread_mutex_t) * nbr);
	}
	else if (i == 2)
	{
		sim->time_to_die = nbr;
	}
	else
		ft_data_param(sim, nbr, i);
	return (0);
}

/*
@brief Converts a string to an integer.
@param arg: String argument to be converted.
@return Converted integer value.
@details Converts the input string to an integer, 
	handling errors if the input is invalid.
*/
int	ft_get_nbr(char *arg)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			nbr = nbr * 10 + (arg[i] - '0');
		else
			return (ft_error_put(NULL, "Error: Numbers only", -1));
		i++;
	}
	return (nbr);
}

/*
@brief Parse command-line arguments.
@param argv Array of argument strings.
@param sim Pointer to the simulation structure (t_sim).
@return 0 on success, non-zero on failure.
@details Parses and validates command-line inputs to set up the simulation.
*/
int	ft_parse(char **argv, t_sim *sim)
{
	int				nbr;
	int				i;

	i = 1;
	while (argv[i])
	{
		nbr = ft_get_nbr(argv[i]);
		if (nbr == -1)
			return (1);
		if (ft_set_data(sim, nbr, i))
			return (1);
		i++;
	}
	return (0);
}
