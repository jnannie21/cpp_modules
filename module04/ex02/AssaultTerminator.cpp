//
// Created by jnannie on 12/23/20.
//

#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator() {
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &other) {
	*this = other;
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &other) {
	if (this == &other)
		return (*this);
	return (*this);
}

AssaultTerminator::~AssaultTerminator() {
	std::cout << "I'll be back..." << std::endl;
}

ISpaceMarine *AssaultTerminator::clone() const {
	AssaultTerminator *copy = new AssaultTerminator;

	*copy = *this;
	return (copy);
}

void AssaultTerminator::battleCry() const {
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void AssaultTerminator::rangedAttack() const {
	std::cout << "* does nothing *" << std::endl;
}

void AssaultTerminator::meleeAttack() const {
	std::cout << "* attacks with chainfists *" << std::endl;
}
