#include "philo.h"

int	ft_set_data(t_sim *sim, int nbr, int i)
{
	if (i == 1)
	{
		if (nbr == 0)
			return (ft_error_put(NULL,
					"Error: Must have philosophers present", 1));
		sim->philo_id = nbr;
		sim->threads = malloc(sizeof(pthread_t) * nbr);
		sim->forks = malloc(sizeof(pthread_mutex_t) * nbr);
	}
	else if (i == 2)
	{
		if (nbr < 60)
			return (ft_error_put(sim,
					"Error: time_to_die cannot be < 60 ms", 1));
		sim->time_to_die = nbr;
	}
	else
		ft_set_rest(sim, nbr, i);
	return (0);
}

int	ft_get_nbr(char *argv)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			nbr = nbr * 10 + (argv[i] - '0');
		else
			return (ft_error_put(NULL, "Usage: <number>", -1));
		i++;
	}
	return (nbr);
}

int	ft_parse(char *argv[], t_sim *sim)
{
	int	nbr;
	int	i;

	i = 1;
	while (argv[i++])
	{
		nbr = ft_get_nbr(argv[i]);
		if (nbr == -1)
			return (1);
		if (ft_set_data(sim, nbr, i))
			return (1);
	}
	if (i == 5)
	{
		sim->eat_counter = -1;
		sim->current_eat = -1;
		sim->max_eat = -1;
	}
	sim->is_dead = 0;
	return (0);
}
