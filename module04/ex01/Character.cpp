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
		this->_ap = 40;
	else
		this->_ap += 10;
}

void Character::equip(AWeapon *weapon) {
	this->_weapon = weapon;
}

void Character::attack(Enemy *enemy) {
	if(this->_weapon)
	{
		if (this->_ap > this->_weapon->getApCost())
		{
			std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
			this->_weapon->attack();
			this->_ap -= this->_weapon->getApCost();
			enemy->takeDamage(this->_weapon->getDamage());
			if (enemy->getHp() == 0)
				delete enemy;
		}
	}
}

std::string const &Character::getName() const {
	return (this->_name);
}

int Character::getAp() const {
	return (this->_ap);
}

AWeapon *Character::getWeapon() const {
	return (this->_weapon);
}

std::ostream &operator<<(std::ostream &stream, Character const &character) {
	if (character.getWeapon())
		stream << character.getName() << " has " << character.getAp() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
	else
		stream << character.getName() << " has " << character.getAp() << " AP and is unarmed" << std::endl;
	return (stream);
}
