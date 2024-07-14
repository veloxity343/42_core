/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:58:46 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/14 15:08:52 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../libft/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include <signal.h>
# include <sys/types.h>

extern pid_t					g_client_pid;
extern volatile sig_atomic_t	g_ack_received;

#endif

/*
1. store the PID
    server remembers PID

2. volatile to prevent compiler optimisation
    - instead of sequential flow
    ensure var can be safely accessed in single operation
    - for read and write, either fully or not at all
    avoid parameter passing or interruption from handler
*/