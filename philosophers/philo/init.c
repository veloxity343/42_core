#include "philo.h"

void	ft_create_mutex(t_sim *sim)
{
	int	i;

	i = 0;
	pthread_mutex_init(sim->msg, NULL);
	pthread_mutex_init(sim->death, NULL);
	pthread_mutex_init(sim->stop, NULL);
	while (i < sim->philo)
		pthread_mutex_init(sim->forks + i++, NULL);
}

void	ft_destroy_all(t_sim *sim, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(sim->death);
	pthread_mutex_destroy(sim->msg);
	pthread_mutex_destroy(sim->stop);
	while (i < sim->philo)
	{
		pthread_mutex_destroy(sim->forks + i);
		pthread_mutex_destroy(philo[i].eat);
		free(philo[i].eat);
		i++;
	}
	free(philo);
	free(sim->forks);
	free(sim->threads);
	free(sim->death);
	free(sim->msg);
	free(sim->stop);
}

t_philo	*ft_philo_init(t_sim *sim)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * sim->philo);
	sim->stop = malloc(sizeof(pthread_mutex_t));
	sim->death = malloc(sizeof(pthread_mutex_t));
	sim->msg = malloc(sizeof(pthread_mutex_t));
	while (++i < sim->philo)
		ft_for_each_philo(sim, philo, i);
	return (philo);
}

void	ft_for_each_philo(t_sim *sim, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].left_hand = i;
	philo[i].right_hand = (i + 1) % sim->philo;
	philo[i].is_dead = NO;
	philo[i].data = sim;
	philo[i].eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[i].eat, NULL);
	if (sim->eat_counter == -1)
		philo[i].eat_counter = -1;
	else
		philo[i].eat_counter = sim->eat_counter;
}

void	ft_print_msg(int id, t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(philo->data->msg);
	time = ft_get_time() - philo->data->start;
	if (id == FORK)
		printf("%u\t%d has taken a fork\n", time, philo->index + 1);
	else if (id == EAT)
		printf("%u\t%d is eating\n", time, philo->index + 1);
	else if (id == SLEEP)
		printf("%u\t%d is sleeping\n", time, philo->index + 1);
	else if (id == THINK)
		printf("%u\t%d is thinking\n", time, philo->index + 1);
	else if (id == DIED)
		printf("%u\t%d has died\n", time, philo->index + 1);
	else if (id == DONE)
		printf("Success! All philosophers made it through without a single food fight.\n");
	if (id != DIED && id != DONE)
		pthread_mutex_unlock(philo->data->msg);
}
