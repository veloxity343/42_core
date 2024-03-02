#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		char *string = argv[1];
		int fd = ft_atoi(argv[2]);
		printf("%s\n", string);
		printf("%d\n", fd);
		ft_putendl_fd(string, fd);
	}
	return (0);
}