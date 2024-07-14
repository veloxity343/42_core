/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:51:31 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/14 11:34:46 by rcheong          ###   ########.fr       */
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
			ft_printf("\nMessage received. Awaiting new message...\n");
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
