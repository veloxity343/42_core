# Standard
NAME	=	philo

# Directories
OBJ_DIR	=	obj/

# Compiler & flags
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror #-pthread -lrt -O3 #-fsanitize=address -fsanitize=thread -g3
IFLAGS	=	-I .
RM		=	rm -rf

# Sources
SRCS	=	$(wildcard *.c)

# Objects
OBJS	=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Colors
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Build rules
all:		$(NAME)
	@echo "$(GREEN)Successfully compiled $(RESET)"

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling\t$(RESET)$<"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Deleting$(RESET)\t"$(OBJ_DIR)
	@$(RM) -rf $(OBJ_DIR)

fclean:	clean
	@echo "$(RED)Deleting$(RESET)\t"$(NAME)
	@$(RM) -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
