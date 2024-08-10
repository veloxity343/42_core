# Standard
NAME	=	so_long

# Directories
LIBFT	=	./libft/libft.a
INC		=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

# MLX
UNAME_S		:= $(shell uname -s)
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -L/opt/homebrew/Cellar/mlx/0.13.0/lib -lmlx -framework OpenGL -framework AppKit

ifeq ($(UNAME_S), Darwin)
	MLX		= $(MLX_MACOS)
	MLX_CO	=
else
	MLX		= $(MLX_LINUX)
	MLX_CO	= $(MLX_LINUX)
endif

# Directories
LIBFT	=	./libft/libft.a
INC		=	inc/
SRC_DIR	=	src/
OBJ_DIR	=	obj/

# Compiler & flags
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g3
IFLAGS	=	-I$(INC)
AR		=	ar -rcs
RM		=	rm -rf

# Source files
SRCS	=	$(SRC_DIR)controls.c \
			$(SRC_DIR)errors.c \
    		$(SRC_DIR)graphics.c \
    		$(SRC_DIR)left_right.c \
			$(SRC_DIR)map.c \
    		$(SRC_DIR)so_long.c \
    		$(SRC_DIR)up_down.c \
       		$(SRC_DIR)validate.c

# Object files
OBJS	=	$(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Build Rules
start:
						@make all

$(LIBFT):
						@make -C ./libft
						
all:					$(NAME)

$(NAME):				$(OBJS) $(LIBFT)
						@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIBFT) $(MLX) -I/opt/homebrew/Cellar/mlx/0.13.0/include -o $(NAME)

$(OBJ_DIR)%.o:			$(SRC_DIR)%.c 
						@mkdir -p $(@D)
						@echo "Compiling $< into $@"
						@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
clean:
						@$(RM) -r $(OBJ_DIR)
						@make clean -C ./libft

fclean:					clean
						@$(RM) $(NAME)
						@$(RM) $(LIBFT)

re:						fclean all

.PHONY:					start all clean fclean re