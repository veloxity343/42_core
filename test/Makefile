# NAME = so_long
CC = gcc
CFLAGS = -fsanitize=address -Wall -Wextra -Werror -ggdb
INCLUDES = -Iincludes -Ilib/libft -Ilib/ft_printf -Ilib/minilibx_macos
# INCLUDES = -Iincludes -Ilib/libft -Ilib/ft_printf -Ilib/minilibx_macos -I/usr/include -Ilib/mlx_linux -O3

# Source files
SCRS_DIR = srcs
ENEMY_DIR = enemy
ENF_DIR = error_and_free
DEBUG_DIR = debug
UTILS_DIR = utils
GNL_DIR = getnextline
MAIN_DIR = main
HOOK_DIR = hooks
SRCS_FILES = $(addprefix $(MAIN_DIR)/, game.c main.c init.c) \
						 $(addprefix $(ENEMY_DIR)/, enemy_utils.c) \
						 $(addprefix $(DEBUG_DIR)/, debug.c) \
						 $(addprefix $(HOOK_DIR)/, hook.c movement.c) \
						 $(addprefix $(ENF_DIR)/, error.c free.c) \
						 $(addprefix $(UTILS_DIR)/, map_utils.c map_utils2.c map_check.c map_check2.c) \
						 $(addprefix $(GNL_DIR)/, get_next_line.c) \

SRCS = $(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

# Object files
OBJS_DIR = objs
OBJS_DIRS = $(OBJS_DIR) $(OBJS_DIR)/$(MAIN_DIR) $(OBJS_DIR)/$(UTILS_DIR) \
			$(OBJS_DIR)/$(ENF_DIR) $(OBJS_DIR)/$(GNL_DIR) $(OBJS_DIR)/$(HOOK_DIR) \
			$(OBJS_DIR)/$(DEBUG_DIR) $(OBJS_DIR)/$(ENEMY_DIR)
OBJS_FILES = $(patsubst %.c,%.o,$(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/,$(OBJS_FILES))

# Librairies
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINF_DIR = lib/ft_printf
PRINTF = $(PRINF_DIR)/libftprintf.a

MLX_DIR = lib/mlx_linux
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS_LINUX = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
LIBS = -L$(LIBFT_DIR) -L$(PRINF_DIR) -lft -lftprintf

#Binary
NAME = so_long

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m
RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
UNDERLINE = \033[4m
BLINK = \033[5m
INVERT = \033[7m
LIGHT_BLUE = \033[94m
YELLOW = \033[33m

# Makefile rules
all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
# 		@echo "$(YELLOW)Compiling $(NAME)$(NC)"
# 		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX_FLAGS_LINUX) -o $(NAME)
# 		@echo "$(GREEN)$(BOLD)$(NAME) has been created$(NC)"
# 		@echo " /\_/\ "
# 		@echo "( o.o )"
# 		@echo " > ^ <"

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL)
		@echo "$(YELLOW)Compiling $(NAME)$(NC)"
		@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
		@echo "$(GREEN)$(BOLD)$(NAME) has been created$(NC)"
		@echo " /\_/\ "
		@echo "( o.o )"
		@echo " > ^ <"

$(OBJS_DIR)/%.o: $(SCRS_DIR)/%.c
		@mkdir -p $(OBJS_DIRS)
		@echo "$(BOLD)$(YELLOW)Compiling $<...$(RESET)"
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# $(MLX):
# 		@echo "$(YELLOW)Compiling mlx...$(RESET)"
# 		@make -C $(MLX_DIR) -s

$(LIBFT):
		@echo "$(YELLOW)Compiling libft...$(RESET)"
		@make -C $(LIBFT_DIR) -s

$(PRINTF):
		@echo "$(YELLOW)Compiling ft_printf...$(RESET)"
		@make -C $(PRINF_DIR) -s

clean:
		@echo "$(RED)Cleaning objects...$(NC)"
		@rm -rf $(OBJS_DIR)
		@make -C $(LIBFT_DIR) clean -s
		@make -C $(PRINF_DIR) clean -s

fclean: clean
		@echo "$(RED)Cleaning $(NAME)...$(NC)"
		@rm -f $(NAME)
		@make -C $(LIBFT_DIR) fclean -s
		@make -C $(PRINF_DIR) fclean -s
		@echo " /\_/\ "
		@echo "( o.o )"
		@echo " > ^ <"
		@echo "$(RED)$(BOLD)$(NAME) has been deleted$(NC)"

re: fclean all

.PHONY: all clean fclean re