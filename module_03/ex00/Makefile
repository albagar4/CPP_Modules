GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = ClapTrap
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I .

SOURCES = main.cpp ClapTrap.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME)!$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@echo "$(RED)Objects removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re