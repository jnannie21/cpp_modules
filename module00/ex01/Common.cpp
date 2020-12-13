//
// Created by Johnette Nannie on 12/12/20.
//

#include "Common.hpp"
#include <iostream>

Common::Common(void) {}

Common::~Common(void) {}

std::string	Common::getLineSafe(void) {
	std::string		str;

	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << std::endl << "eof was reached. exiting." << std::endl;
		std::exit(1);
	}
	return (str);
}
