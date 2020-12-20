CC = clang++
CFLAGS = -c -Wall -Wextra -Werror -std=c++98
MAIN_SOURCES = 	main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp
NAME = a.out

OBJECTS = $(MAIN_SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
