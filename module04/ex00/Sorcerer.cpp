//
// Created by jnannie on 12/22/20.
//

#include "Sorcerer.hpp"
#include <iostream>

Sorcerer::Sorcerer(void) {

}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << this->_name << ", " << this->_title << ", " << "is born." << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &other) {
	this->_name = other.getName();
	this->_title = other.getTitle();

}

Sorcerer &Sorcerer::operator=(Sorcerer const &other) {
	this->_name = other.getName();
	this->_title = other.getTitle();
	return (*this);
}

Sorcerer::~Sorcerer(void) {
	std::cout << this->_name << ", " << this->_title << ", " << "is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName(void) const {
	return (this->_name);
}

std::string Sorcerer::getTitle(void) const {
	return (this->_title);
}

void Sorcerer::polymorph(Victim const &victim) const {
	victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &stream, Sorcerer const &sorcerer) {
	stream << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
	return (stream);
}
