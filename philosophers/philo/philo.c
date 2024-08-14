#include "philo.h"

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

int	main(int argc, char *argv[])
{
	int	i;
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
		while (i < sim.philo_id)
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