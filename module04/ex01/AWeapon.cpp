//
// Created by jnannie on 12/22/20.
//

#include "AWeapon.hpp"

AWeapon::AWeapon() : _name(""), _apCost(0), _damage(0), {

}

AWeapon::AWeapon(std::string const &name, int apCost, int damage) : _name(name), _apCost(apCost), _damage(damage) {

}

AWeapon::AWeapon(AWeapon const &other) {
	*this = other;
}

AWeapon &AWeapon::operator=(AWeapon const &other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->_damage = other._damage;
		this->_apCost = other._apCost;
	}
	return (*this);
}

AWeapon::~AWeapon() {

}

std::string const &AWeapon::getName() const {
	return (this->_name);
}

int AWeapon::getApCost() const {
	return (this->_apCost);
}

int AWeapon::getDamage() const {
	return (this->_damage);
}
