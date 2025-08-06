# Standard
NAME	=	RPN

# Directories
INC		=	inc/
SRC_DIR	=	src
OBJ_DIR	=	obj

# Compiler & flags
CC		=	c++
WFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic
IFLAGS	=	-I$(INC)
DSYM	=	-g3
FSAN	=	-fsanitize=address $(DSYM)
CFLAGS	=	$(WFLAGS) $(IFLAGS)
RM		=	rm -f

# Sources & objects
SRC		=	$(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ		=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Colors
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
BLUE	=	\033[1;34m
RESET	=	\033[0m

# Build rules
all:		$(NAME)
	@echo "$(GREEN)Successfully compiled!$(RESET)"

$(NAME):	$(OBJ)
	@echo "\n$(BLUE)Building$(RESET)\t$(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)Compiling\t$(RESET)%-33.33s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

# Scruba dub dub
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	$(RM) -rf $(OBJ_DIR); \
	echo "$(RED)Deleting$(RESET)\t"$(OBJ_DIR); else \
	echo "$(BLUE)No $(NAME) objects to remove."; \
	fi;

fclean:	clean
	@if [ -f "$(NAME)" ]; then \
	$(RM) -f $(NAME); \
	echo "$(RED)Deleting$(RESET)\t"$(NAME); else \
	echo "$(BLUE)No executable $(NAME) to remove.$(RESET)"; \
	fi;

re:		fclean all

test: re
	@echo "$(YELLOW)Testing...$(RESET)"
	@clear
	./$(NAME) "3 4 + 2 * 7 /"
	./$(NAME) "3 4 + 2 * 7 / 5 -"
	./$(NAME) "1 + 1"
	./$(NAME) "12a 4 +"
	./$(NAME) "4 +"
	./$(NAME) "4 0 /"
	./$(NAME) "1 2 3 +"
	./$(NAME) ""
	./$(NAME) "2 2 ^"

# Debugging
asan:	CFLAGS	+=	$(FSAN)
asan:	re
	@echo "$(YELLOW)Running with AddressSanitizer...$(RESET)"
	./$(NAME)

valgrind:	$(NAME)
	@echo "$(YELLOW)Running with Valgrind...$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re test asan valgrind
