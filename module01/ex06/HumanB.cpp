//
// Created by jnannie on 12/15/20.
//

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _name(name) , _weapon(NULL) {

}

void HumanB::attack(void) const {
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
