//
// Created by jnannie on 12/20/20.
//

#include "BaseTrap.hpp"
#include <iostream>

bool BaseTrap::_isRandInitialized = false;

BaseTrap::BaseTrap(void) :
	_type("BaseTrap"),
	_hitPoints(0),
	_maxHitPoints(0),
	_energyPoints(0),
	_maxEnergyPoints(0),
	_level(0),
	_name("unnamed"),
	_meleeAttackDamage(0),
	_rangedAttackDamage(0),
	_armorDamageReduction(0) {
	_initializeRand();
}

BaseTrap::BaseTrap(const BaseTrap &f) {
	*this = f;
}

BaseTrap &BaseTrap::operator=(const BaseTrap &f) {
	this->_type = f._type;
	this->_hitPoints = f._hitPoints;
	this->_maxHitPoints = f._maxHitPoints;
	this->_energyPoints = f._energyPoints;
	this->_maxEnergyPoints = f._maxEnergyPoints;
	this->_level = f._level;
	this->_name = f._name;
	this->_meleeAttackDamage = f._meleeAttackDamage;
	this->_rangedAttackDamage = f._rangedAttackDamage;
	this->_armorDamageReduction = f._armorDamageReduction;
	return (*this);
}

BaseTrap::~BaseTrap(void) {
	std::cout << this->_name << " is destructed." << std::endl;
}

void BaseTrap::rangedAttack(std::string const &target) {
	std::cout << this->_name << " attacks " << target << " with ranged attack, causing "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void BaseTrap::meleeAttack(std::string const &target) {
	std::cout << this->_name << " attacks " << target << " with melee attack, causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void BaseTrap::takeDamage(unsigned int amount) {
	unsigned int damage = 0;

	if (amount > this->_armorDamageReduction)
		damage = amount - this->_armorDamageReduction;
	if (this->_hitPoints < damage)
		damage = this->_hitPoints;
	this->_hitPoints -= damage;
	std::cout << this->_name << " takes " << damage << " points of damage!" << std::endl;
}

void BaseTrap::beRepaired(unsigned int amount) {
	if ((this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount)
		|| (this->_hitPoints + amount > this->_maxHitPoints))
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << this->_name << " is repaired by " << amount << " points." << std::endl;
}

void BaseTrap::_initializeRand(void) {
	if (BaseTrap::_isRandInitialized)
		return ;
	std::srand(std::time(NULL));
	BaseTrap::_isRandInitialized = true;
}
