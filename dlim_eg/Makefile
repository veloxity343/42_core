# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlim-yua <dlim-yua@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 16:16:24 by dlim-yua          #+#    #+#              #
#    Updated: 2024/06/16 16:16:26 by dlim-yua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_B		=	so_long_bonus

LIBFT_DIR	=	./libft/
LIBFT		=	libft.a

SRC			=	./mandatory/*.c
SRC_B		=	./bonus/*.c

CC			=	cc

FLAG_C		=	-Wall -Wextra -Werror
FLAG_F		=	-lmlx -framework OpenGL -framework Appkit

all:	$(NAME)

bonus:	$(NAME_B)

$(NAME):
		@make -C $(LIBFT_DIR)
		@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
		@$(CC) $(FLAG_C) $(FLAG_F) $(SRC) $(NAME) -o $(NAME)

$(NAME_B):
		@make -C $(LIBFT_DIR)
		@cp $(LIBFT_DIR)$(LIBFT) $(NAME_B)
		@$(CC) $(FLAG_C) $(FLAG_F) $(SRC_B) $(NAME_B) -o $(NAME_B)

clean:
		@make clean -C $(LIBFT_DIR)

fclean:	clean
		@rm -f $(LIBFT_DIR)$(LIBFT)
		@rm -rf $(NAME)
		@rm -rf $(NAME_B)

re:		fclean	all
