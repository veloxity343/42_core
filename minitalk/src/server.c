#include "../inc/minitalk.h"

void	sig_handler(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv) 
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
		ft_printf("Usage: %s\n", argv[0]);
	pid = getpid();
	ft_printf("PID: %d\nWaiting for a message...\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler); 
		pause();
	}
	return (0);
}
