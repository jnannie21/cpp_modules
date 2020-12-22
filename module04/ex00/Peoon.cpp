//
// Created by jnannie on 12/22/20.
//

#include "Peoon.hpp"
#include <iostream>

Peoon::Peoon(void) : Victim() {
	std::cout << "Zoog zoog." << std::endl;
}

Peoon::Peoon(std::string name) : Victim(name) {
	std::cout << "Zoog zoog." << std::endl;
}

Peoon::Peoon(const Victim &other) : Victim(other) {
	std::cout << "Zoog zoog." << std::endl;
}

Peoon &Peoon::operator=(const Peoon &other) {
	Victim::operator =(other);
	return (*this);
}

Peoon::~Peoon(void) {
	std::cout << "O_O..." << std::endl;
}

void Peoon::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a brown frog!" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Peoon const &peoon) {
	stream << "I am " << peoon.getName() << " and I like dogs!" << std::endl;
	return (stream);
}
