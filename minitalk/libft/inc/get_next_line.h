/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:02:04 by rcheong           #+#    #+#             */
/*   Updated: 2024/07/14 11:02:05 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

/* ---------- GNL ---------- */

char	*trim_buffer(char *buffer);
char	*extract_line(char *buffer);
char	*join_free(char *res, char *buffer);
char	*read_cat(int fd, char *res);
char	*get_next_line(int fd);

#endif