#include "../inc/push_swap.h"

void	free_array(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		i++;
	while (i >= 0)
		free((*str)[i--]);
	free(*str);
}

void	error_exit(int nb)
{
	(void)nb;
	ft_printf("Error: ");
	exit(1);
}
