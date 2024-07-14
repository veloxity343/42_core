/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:51:31 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/14 14:40:35 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

pid_t	g_client_pid = 0;

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static int	i = 0;

	(void)context;
	if (g_client_pid == 0)
	{
		g_client_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		if (i == '\n')
		{
			kill(g_client_pid, SIGUSR1);
			g_client_pid = 0;
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
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
	while (1)
	{
		pause();
	}
	return (0);
}

/* configure using sa.sa_sigaction because if SA_SIGINFO flag is 
specified, the signal handler address is passed via the sa_sigaction 
field instead of sa_handler field

sa_mask: signals to be blocked set to 0 - no blockage

sigaction takes these args: signum, act, old_act;

sig_handler: the "info" argument is a pointer to siginfo_t, a 
structure containing further information about the signal:
sends process ID of client to server

context is a pointer to a struct that contains signal context 
information that was saved on the user-space stack by the kernel */