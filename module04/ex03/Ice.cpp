//
// Created by jnannie on 12/23/20.
//

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {

}

Ice::Ice(Ice const &other) : AMateria(other) {

}

Ice &Ice::operator=(Ice const &other) {
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice() {

}

AMateria *Ice::clone() const {
	Ice *newIce = new Ice;

	*newIce = *this;
	return (newIce);
}

void Ice::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
