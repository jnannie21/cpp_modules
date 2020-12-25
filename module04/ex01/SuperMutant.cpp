//
// Created by jnannie on 12/22/20.
//

#include "SuperMutant.hpp"
#include <iostream>

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant") {
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &other) : Enemy(other) {

}

SuperMutant &SuperMutant::operator=(SuperMutant const &other) {
	if (this == &other)
		return (*this);

	Enemy::operator=(other);
	return (*this);
}

SuperMutant::~SuperMutant() {
	std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage) {
	Enemy::takeDamage(damage - 3);
}
