#include "../inc/push_swap.h"

static char	build_string(char *argv[], char **stack)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (!argv[i][0])
		{
			free(*stack);
			error_exit(0);
			ft_printf("Empty string for argument %d.", argv[i]);
		}
		*stack = ft_strjoin(*stack, argv[i]);
		*stack = ft_strjoin(*stack, ' ');
	}
	return (*stack);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	char	*stack;

	if (argc < 2)
		ft_printf("Error: Insufficient arguments. Usage: %s <numbers>\n",
			argv[0]);
	else
	{
		stack = NULL;
		stack = build_string(argv, &stack);
		if (!is_valid(&stack) || !check_duplicate(&stack))
		{
			error_exit(0);
			ft_printf("Arguments must be unique numbers.\n");
		}
		a = NULL;
	}
	return (0);
}
