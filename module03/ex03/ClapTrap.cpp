//
// Created by jnannie on 12/20/20.
//

#include "ClapTrap.hpp"
#include <iostream>

bool ClapTrap::_isRandInitialized = false;

ClapTrap::ClapTrap(void) :
	_type("ClapTrap"),
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
	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &f) {
	*this = f;
	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f) {
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

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap" << " " << this->_name << " is destructed." << std::endl;
}

std::string ClapTrap::getName(void) const {
	return (this->_name);
}

std::string ClapTrap::getType(void) const {
	return (this->_type);
}

void ClapTrap::rangedAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with ranged attack, causing "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::meleeAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with melee attack, causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	unsigned int damage = 0;

	if (amount > this->_armorDamageReduction)
		damage = amount - this->_armorDamageReduction;
	if (this->_hitPoints < damage)
		damage = this->_hitPoints;
	this->_hitPoints -= damage;
	std::cout << this->_type << " " << this->_name << " takes " << damage << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if ((this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount)
		|| (this->_hitPoints + amount > this->_maxHitPoints))
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << this->_type << " " << this->_name << " is repaired by " << amount << " points." << std::endl;
}

void ClapTrap::_initializeRand(void) {
	if (ClapTrap::_isRandInitialized)
		return ;
	std::srand(std::time(NULL));
	ClapTrap::_isRandInitialized = true;
}
