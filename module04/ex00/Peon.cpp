//
// Created by jnannie on 12/22/20.
//

#include "Peon.hpp"
#include <iostream>

Peon::Peon(void) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name) : Victim(name) {
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Victim &other) {
	this->_name = other.getName();
}

Peon &Peon::operator=(const Peon &other) {
	this->_name = other.getName();
	return (*this);
}

Peon::~Peon(void) {
	std::cout << "Bleuark..." << std::endl;
}

std::string Peon::getName(void) const {
	return (this->_name);
}

void Peon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a pink pony!" << std::endl;
}
