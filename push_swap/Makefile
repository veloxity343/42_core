# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and Flags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
SRCS 				= 	$(SRC_DIR)main.c \
						$(SRC_DIR)validate.c \
						$(SRC_DIR)utils.c \
						$(SRC_DIR)create_stack.c \
						$(SRC_DIR)sort.c \
						$(SRC_DIR)operations.c \
						$(SRC_DIR)midpt_to_b.c \
						$(SRC_DIR)calculate_cost.c \
						$(SRC_DIR)target.c \
						$(SRC_DIR)op_double.c \
						$(SRC_DIR)alloc_to_a.c \
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build Rules
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re
