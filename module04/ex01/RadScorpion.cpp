//
// Created by jnannie on 12/22/20.
//

#include "RadScorpion.hpp"
#include <iostream>

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion") {
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &other) : Enemy(other) {

}

RadScorpion &RadScorpion::operator=(RadScorpion const &other) {
	Enemy::operator=(other);
	return (*this);
}

RadScorpion::~RadScorpion() {
	std::cout << "* SPROTCH *" << std::endl;
}