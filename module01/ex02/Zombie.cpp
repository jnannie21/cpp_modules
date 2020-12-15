//
// Created by jnannie on 12/14/20.
//

#include "Zombie.hpp"
#include <iostream>

const std::string Zombie::_type_names[] = {
		"none",
		"homer",
		"hawking",
		"ninja",
		"t-800",
};

Zombie::Zombie(std::string name, ZombieType type) : _name(name), _type(type) {

}

Zombie::~Zombie(void) {
	std::cout << "zombie " << this->_name << " destructed" << std::endl;
}

void Zombie::announce(void) const {
	std::cout << "<" << this->_name << " (" << this->_type_names[this->_type] << ")> " << "Braiiiiiiinnnssss..." << std::endl;
}
