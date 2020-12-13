CC = clang++
CFLAGS = -c -Wall -Wextra -Werror -std=c++98
MAIN_SOURCES =	main.cpp Contact.cpp Phonebook.cpp Common.cpp
HEADER = Contact.hpp Phonebook.hpp Common.hpp
NAME = phonebook

OBJECTS = $(MAIN_SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
