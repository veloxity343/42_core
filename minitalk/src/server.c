#include "../inc/minitalk.h"

/* void	sig_handler(int sig)
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
	ft_printf("PID: %d\nWaiting for message...\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler); 
		pause();
	}
	return (0);
} */

pid_t client_pid = 0;

void sig_handler(int sig, siginfo_t *info, void *context)
{
    static int bit = 0;
    static int i = 0;

    (void)context;

    if (client_pid == 0) {
        client_pid = info->si_pid;
    }

    if (sig == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        if (i == '\n') {
            ft_printf("\nMessage received.\n");
            kill(client_pid, SIGUSR1);
            client_pid = 0;
        }
        bit = 0;
        i = 0;
    }
}

int main(int argc, char **argv)
{
    pid_t pid;
    struct sigaction sa;

    (void)argv;
    if (argc != 1) {
        ft_printf("Usage: %s\n", argv[0]);
        return (1);
    }
    pid = getpid();
    ft_printf("PID: %d\nWaiting for message...\n", pid);

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = sig_handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) {
        pause();
    }
    return (0);
}
