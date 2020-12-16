#include <fstream>
#include <iostream>
#include "StreamEditor.hpp"

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	StreamEditor editor(argv[1], argv[2], argv[3]);
	editor.replace();
	if (editor.getError())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
