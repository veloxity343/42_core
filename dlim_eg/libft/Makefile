# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 17:30:21 by dlim-yua          #+#    #+#              #
#    Updated: 2024/02/24 17:30:31 by dlim-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_printf_utils.c get_next_line.c

SRCS_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS:.c=.o) $(SRCS_BONUS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

LIBC		=	ar rcs

all:		$(OBJS) $(NAME)

%.o:		%.c
				$(CC) $(CFLAGS) -c $< -o $(<:c=o)

$(NAME):	$(OBJS)
				$(LIBC) $(NAME) $(OBJS)
clean:
				rm -f $(OBJS) $(OBJS_BONUS)

fclean:		clean
				rm -f $(NAME)

bonus:		$(OBJS_BONUS)
				$(LIBC) $(NAME) $(OBJS_BONUS)

re:			fclean all

.PHONY:		all clean fclean re
