//
// Created by jnannie on 12/23/20.
//

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {

}

Cure::Cure(Cure const &other) : AMateria(other) {

}

Cure &Cure::operator=(Cure const &other) {
	if (this == &other)
		return (*this);

	AMateria::operator=(other);
	return (*this);
}

Cure::~Cure() {

}

AMateria *Cure::clone() const {
	Cure *newCure = new Cure;

	*newCure = *this;
	return (newCure);
}

void Cure::use(ICharacter &target) {
	AMateria::use(target);
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
