#include "../inc/philo.h"



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
	sim->is_dead = NO;
	return (0);
}
