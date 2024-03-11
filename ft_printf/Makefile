#Variables

NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
SRCB_DIR	= srcb/
OBJB_DIR	= objb/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

#Sources

SRC_FILES	=	ft_printf ft_parse ft_ismod ft_flags \
				ft_print_char ft_print_str ft_print_ptr \
				ft_print_int ft_print_unsigned ft_print_hex \
				ft_print_pad ft_get_len ft_printf_itoa ft_printf_xtoa \

SRCB_FILES	=	ft_printf_bonus ft_parse_bonus ft_ismod_bonus ft_flags_bonus \
				ft_print_char_bonus ft_print_str_bonus ft_print_ptr_bonus \
				ft_print_int_bonus ft_print_unsigned_bonus ft_print_hex_bonus \
				ft_print_pad_bonus ft_get_len_bonus ft_printf_itoa_bonus ft_printf_xtoa_bonus \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRCB 		= 	$(addprefix $(SRCB_DIR), $(addsuffix .c, $(SRCB_FILES)))
OBJB		=	$(addprefix $(OBJB_DIR), $(addsuffix .o, $(SRCB_FILES)))

###

OBJF		=	.cache_exists
OBJBF		=	.cache_exists_bonus

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

bonus: $(OBJB) 
	$(AR) $(NAME) $(OBJB)

$(OBJB_DIR)%.o: $(SRCB_DIR)%.c | $(OBJBF)
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJBF):
			@mkdir -p $(OBJB_DIR)

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf $(OBJB_DIR)
			@make clean -C $(LIBFT)

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a

re:			fclean all

norm:
			@norminette $(SRC) $(SRCB) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm