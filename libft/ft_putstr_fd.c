#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
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
		ft_putstr_fd(string, fd);
	}
	return (0);
}