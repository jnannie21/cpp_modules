//
// Created by jnannie on 12/22/20.
//

#include "PlasmaRifle.hpp"
#include <iostream>

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21) {

}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &other) : AWeapon(other) {

}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &other) {
	AWeapon::operator=(other);
	return (*this);
}

PlasmaRifle::~PlasmaRifle() {

}

void PlasmaRifle::attack() const {
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
