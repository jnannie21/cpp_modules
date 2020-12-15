//
// Created by jnannie on 12/15/20.
//

#include <iostream>
#include <string>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *pointer = &string;
	std::string &reference = string;

	std::cout << *pointer << std::endl;
	std::cout << reference << std::endl;
	return (0);
}
