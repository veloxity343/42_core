# Standard
NAME				= client
SVR					= server

# Directories
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source files
SRCCL 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAME)))
SRCSV 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVR)))

OBJCL 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAME)))
OBJSV 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVR)))

# Targets
start:				
					@make all

$(LIBFT):
					@make -C ./libft

all:				$(NAME) $(SVR)		

$(NAME):			$(OBJCL) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJCL) $(LIBFT) -o $(NAME)

$(SVR):				$(OBJSV) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJSV) $(LIBFT) -o $(SVR)

# Compile
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
			
fclean:				clean
					@$(RM) $(NAME) $(SVR)
					@$(RM) $(LIBFT)

re:					fclean all

.PHONY:				start all clean fclean re