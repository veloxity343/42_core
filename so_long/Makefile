# Standard
NAME				=	so_long

# Directories
LIBFT				=	./libft/libft.a
INC					=	inc/
SRC_DIR				=	src/
OBJ_DIR				=	obj/

# Mlx
UNAME_S		:= $(shell uname -s)
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -lmlx -framework OpenGL -framework AppKit
ifeq ($(UNAME_S), Darwin)
	MLX		= $(MLX_MACOS)
	MLX_CO	=
else
	MLX		= $(MLX_LINUX)
	MLX_CO	= $(MLX_LINUX)
endif

# Compiler & flags
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g3
AR			= ar -rcs
RM			= rm -rf
