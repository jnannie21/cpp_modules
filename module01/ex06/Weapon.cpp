//
// Created by jnannie on 12/15/20.
//

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {

}

const std::string &Weapon::getType(void) const {
	return (this->_type);
}

void Weapon::setType(const std::string &type) {
	this->_type = type;
}
