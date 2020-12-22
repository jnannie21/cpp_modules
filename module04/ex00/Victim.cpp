//
// Created by jnannie on 12/22/20.
//

#include "Victim.hpp"
#include <iostream>

Victim::Victim(void) {
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(std::string name) : _name(name) {
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &other) {
	this->_name = other.getName();
	std::cout << "Some random victim called " << this->_name << " just appeared!" << std::endl;
}

Victim &Victim::operator=(const Victim &other) {
	if (this != &other)
		this->_name = other.getName();
	return (*this);
}

Victim::~Victim(void) {
	std::cout << "Victim " << this->_name << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getName(void) const {
	return (this->_name);
}

void Victim::getPolymorphed(void) const {
	std::cout << this->_name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &stream, Victim const &victim) {
	stream << "I am " << victim.getName() << " and I like otters!" << std::endl;
	return (stream);
}
