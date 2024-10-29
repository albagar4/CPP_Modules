GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

NAME = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I .

SOURCES = main.cpp PmergeMe.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME)!$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

amount:		
		@read -p "Enter an amount of numbers: " numbers; \
		read -p "Enter the maximum number allowed: " max; \
		./PmergeMe `shuf -i 1-$$max -n $$numbers`

clean:
	@rm -f $(OBJECTS)
	@echo "$(RED)Objects removed!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed!$(RESET)"

re: fclean all

.PHONY: all amount clean fclean re