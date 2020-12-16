#include <fstream>
#include <iostream>
#include "Replacer.hpp"

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	Replacer replacer(argv[1], argv[2], argv[3]);
	replacer.replace();
	if (replacer.getError())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
