/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:50:59 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/14 13:22:36 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

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

void	send_message(pid_t pid, const char *msg)
{
	while (*msg != '\0')
	{
		send_bits(pid, *msg);
		msg++;
	}
	send_bits(pid, '\n');
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		signal(SIGUSR1, ack_handler);
		send_message(pid, msg);
		while (!g_ack_received)
		{
			pause();
		}
		ft_printf("Message received.\n");
	}
	else
	{
		ft_printf("Usage: %s <PID> <STRING>\n", argv[0]);
		return (1);
	}
	return (0);
}
