# Standard
NAME	=	replace

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
CFLAGS	=	$(WFLAGS)
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
	@if ls *.txt *.replace 1> /dev/null 2>&1; then \
		$(RM) *.txt *.replace; \
		echo "$(RED)Deleting$(RESET)\t.txt and .replace files"; \
	else \
		echo "$(BLUE)No .txt or .replace files to remove.$(RESET)"; \
	fi;

re:		fclean all

test: re
	@echo "$(BLUE)Creating test .txt files$(RESET)"
	@echo "you are no longer my apprentice" > test.txt
	@echo "In quiet nights, the stars shine clear," > test2.txt
	@echo "Their twinkling lights seem oh so near." >> test2.txt
	@echo "In quiet nights, the moon’s soft glow," >> test2.txt
	@echo "Guides our dreams like a river's flow." >> test2.txt
	@echo "$(YELLOW)Running test case...$(RESET)"
	./$(NAME) test.txt apprentice master
	./$(NAME) test2.txt "In quiet nights" "On wintry heights"

# Debugging
asan:	CFLAGS	+=	$(FSAN)
asan:	re
	@echo "$(YELLOW)Running with AddressSanitizer...$(RESET)"
	./$(NAME)

.PHONY: all clean fclean re test asan
