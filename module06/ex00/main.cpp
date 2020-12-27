//
// Created by jnannie on 12/26/20.
//

#include "Converter.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "wrong number of arguments" << std::endl;
		return 0;
	}

	try {
		Converter converter(argv[1]);
		converter.printValues();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

//	std::cout << std::fixed << std::numeric_limits<float>::max() << std::endl;
//	std::cout << std::fixed << std::numeric_limits<float>::lowest() << std::endl;