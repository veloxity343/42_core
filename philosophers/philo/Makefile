# Standard
NAME	=	philo

# Directories
OBJ_DIR	=	obj

# Compiler & flags
WFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	-I .
DSYM	=	-g3
FSAN	?=
CFLAGS	=	$(WFLAGS) $(IFLAGS) -pthread $(FSAN)
CC		=	gcc
RM		=	rm -rf

# Sources
SRCS	=	$(wildcard *.c)

# Objects
OBJS	=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Colors
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
RESET	=	\033[0m

# Build rules
all:		$(NAME)
	@echo "$(GREEN)Successfully compiled philo!$(RESET)"

$(NAME):	$(OBJS)
	@echo "\n"
	@echo "$(BLUE)Building$(RESET)\t$(NAME)"
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling\t$(RESET)%-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Deleting$(RESET)\t"$(OBJ_DIR)
	@$(RM) -rf $(OBJ_DIR)

fclean:	clean
	@echo "$(RED)Deleting$(RESET)\t"$(NAME)
	@$(RM) -f $(NAME)

re:		fclean all

# Sanitizer targets
thread:	FSAN = -fsanitize=thread $(DSYM)
addr:	FSAN = -fsanitize=address $(DSYM)

thread addr:	fclean test

# Test
test:	$(NAME)
	@echo "$(BLUE)Testing with debugging on$(RESET)"
	@echo "$(YELLOW)Running philo...$(RESET)"
	./$(NAME) 5 800 200 200 7

norm:
	norminette

.PHONY:	all clean fclean re thread addr test norm
