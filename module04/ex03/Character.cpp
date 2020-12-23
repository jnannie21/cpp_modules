//
// Created by jnannie on 12/23/20.
//

#include "Character.hpp"
#include <stddef.h>

Character::Character() : _name(""), _inventory() {

}

Character::Character(std::string const &name) : _name(name), _inventory() {

}

Character::Character(Character const &other) : _name(""), _inventory() {
	*this = other;
}

Character &Character::operator=(Character const &other) {
	if (this == &other)
		return (*this);

	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];

	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}

	this->_name = other._name;
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

std::string const &Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria *m) {
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == m)
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;

	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || !this->_inventory[idx])
		return ;

	this->_inventory[idx]->use(target);
}
