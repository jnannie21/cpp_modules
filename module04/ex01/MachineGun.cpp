//
// Created by jnannie on 12/25/20.
//

#include "MachineGun.hpp"
#include <iostream>

MachineGun::MachineGun() : AWeapon("Machine Gun", 10, 100) {

}

MachineGun::MachineGun(MachineGun const &other) : AWeapon(other) {

}

MachineGun &MachineGun::operator=(MachineGun const &other) {
	AWeapon::operator=(other);
	return (*this);
}

MachineGun::~MachineGun() {

}

void MachineGun::attack() const {
	std::cout << "* trrrrrrrrrrrrr... *" << std::endl;
}

