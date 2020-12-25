//
// Created by jnannie on 12/25/20.
//

#include "Krang.hpp"
#include <iostream>

Krang::Krang() : Enemy(250, "Krang") {

}

Krang::Krang(Krang const &other) : Enemy(other) {

}

Krang &Krang::operator=(Krang const &other) {
	if (this == &other)
		return (*this);

	Enemy::operator=(other);
	return (*this);
}

Krang::~Krang() {
	std::cout << "Fu(*&g turtles..." << std::endl;
}