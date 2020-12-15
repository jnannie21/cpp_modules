//
// Created by jnannie on 12/14/20.
//

#include "Zombie.hpp"
#include <iostream>

#define DEFAULT_ZOMBIE_NAME "noname"

const std::string Zombie::_type_names[] = {
		"none",
		"homer",
		"hawking",
		"ninja",
		"t-800",
};

Zombie::Zombie(void) : _name(DEFAULT_ZOMBIE_NAME), _type(ZOMBIE_TYPE_NONE) {

}

Zombie::Zombie(std::string name, ZombieType type) : _name(name), _type(type) {

}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::setType(ZombieType type) {
	this->_type = type;
}

void Zombie::announce(void) const {
	std::cout << "<" << this->_name << " (" << this->_type_names[this->_type] << ")> " << "Braiiiiiiinnnssss..." << std::endl;
}
