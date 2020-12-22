//
// Created by jnannie on 12/22/20.
//

#include "Character.hpp"
#include <iostream>

Character::Character() : _name(""), _ap(40), _weapon(NULL) {

}

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(NULL) {

}

Character::Character(Character const &other) {
	*this = other;
}

Character &Character::operator=(Character const &other) {
	if (this != &other)
	{
		this->_name = other._name;
		this->_ap = other._ap;
		this->_weapon = other._weapon;
	}
	return (*this);
}

Character::~Character() {

}

void Character::recoverAP() {
	if (this->_ap > 40 - 10)
		this->_app = 40;
	else
		this->_app += 10;
}

void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if(this->_weapon)
	{
		if (this->_ap > this->_weapon->getAPCost())
		{
			this->_ap = this->_ap - this->_weapon->getAPCost();
			this->_weapon->attack();
			enemy->takeDamage(this->_weapon->getDamage());
			if (enemy->getHp() == 0)
				delete enemy;
			std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
		}
		else
			this->_ap = 0;
	}
}

std::string const &Character::getName() const {
	return (this->_name);
}

//int Character::getAp() const {
//	return (this->_ap);
//}

//AWeapon *Character::getWeapon() const {
//	return (this->_weapon);
//}
//
//AWeapon *Character::_getWeapon() {
//	return (this->_weapon);
//}