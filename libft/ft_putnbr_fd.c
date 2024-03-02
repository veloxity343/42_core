#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int n = ft_atoi(argv[1]);
		int fd = ft_atoi(argv[2]);
		printf("%d\n%d\n", n, fd);
		printf("%d\n", fd);
		ft_putnbr_fd(n, fd);
	}
	return (0);
}