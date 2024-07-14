/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:58:46 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/14 11:26:38 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>

extern volatile sig_atomic_t	g_ack_received;
extern pid_t					g_client_pid;

void							ack_handler(int sig);
void							send_bits(pid_t pid, char c);
void							sig_handler(int sig, siginfo_t *info,
									void *context);

#endif
