# Standard
NAME		=	philo

# Directories
INC			=	inc/
SRC_DIR		=	src/
OBJ_DIR		=	obj/
SRCB_DIR	=	srcb/
OBJB_DIR	=	objb/

# Compiler & flags
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=address -g3
IFLAGS	=	-I$(INC)
RM		=	rm -rf

# Sources
SRCS	=	$(SRC_DIR)

SRCBS	=	$(SRCB_DIR)

# Object files
OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
OBJBS	=	$(SRCBS:$(SRCB_DIR)%.c=$(OBJB_DIR)%.o)

# Colors
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# Build rules
all:			$(NAME)
	@echo "$(BLUE)██████████████████████ Successfully compiled ███████████████████████$(RESET)"

$(NAME):		$(OBJS)
	$(NAME) $(OBJ)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
	@mkdir -p $(@D)
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

bonus:			$(OBJB)
	$(NAME) $(OBJB)

$(OBJB_DIR)%.o:	$(SRCB_DIR)%.c
	@mkdir -p $(@D)
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Deleting$(RESET): " $(OBJ_DIR)
	@$(RM) -rf $(OBJ_DIR)
	@$(RM) -rf $(OBJB_DIR)

fclean:	clean
	@echo "$(RED)Deleting$(RESET): " $(NAME)
	@$(RM) -f $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re
