//
// Created by jnannie on 12/23/20.
//

#include "AMateria.hpp"

AMateria::AMateria() : _xp(0) {

}

AMateria::AMateria(std::string const &type) : _type(type), _xp(0) {

}

AMateria::AMateria(AMateria const &other) : _xp(other._xp) {

}

AMateria &AMateria::operator=(AMateria const &other) {
	if (this == &other)
		return (*this);

	this->_xp = other._xp;
	return (*this);
}

AMateria::~AMateria() {

}

std::string const &AMateria::getType() const {
	return (this->_type);
}

unsigned int AMateria::getXP() const {
	return (this->_xp);
}

void AMateria::use(ICharacter &target) {
	(void)target;
	this->_xp += 10;
}
