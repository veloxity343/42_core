#include "../inc/minitalk.h"

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (*msg != '\0')
		{
			send_bits(pid, *msg);
			msg++;
		}
		send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Usage: %s <PID> <STRING>\n", argv[0]);
		return (1);
	}
	return (0);
}