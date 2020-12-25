//
// Created by jnannie on 12/22/20.
//

#include "Peon.hpp"
#include <iostream>

Peon::Peon(void) : Victim() {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &other) : Victim(other) {
	std::cout << "Zog zog." << std::endl;
}

Peon &Peon::operator=(const Peon &other) {
	Victim::operator =(other);
	return (*this);
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}
