//
// Created by jnannie on 12/20/20.
//

#include "ScavTrap.hpp"
#include <iostream>

bool ScavTrap::_isRandInitialized = false;

const std::string ScavTrap::_randomChallengePool[] = {
	"Poker",
	"Darts",
	"Caucus race",
	"Words",
	"Touch and run"
};

ScavTrap::ScavTrap(void) {

}

ScavTrap::ScavTrap(std::string name) {
	this->_type = "ScavTrap";
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f) {
	*this = f;
	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f) {
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

ScavTrap::~ScavTrap(void) {
	std::cout << this->_type << " " << this->_name << " is destructed." << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	unsigned int damage = 0;

	if (amount > this->_armorDamageReduction)
		damage = amount - this->_armorDamageReduction;
	if (this->_hitPoints < damage)
		damage = this->_hitPoints;
	this->_hitPoints -= damage;
	std::cout << this->_name << " takes " << damage << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if ((this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount)
		|| (this->_hitPoints + amount > this->_maxHitPoints))
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << this->_name << " is repaired by " << amount << " points." << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target) {
	std::cout << this->_type << " " << this->_name << " uses ranged attack on " << target << " causing "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target) {
	std::cout << this->_type << " " << this->_name << " uses melee attack on " << target << " causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::challengeNewcomer(void) {
	int index = std::rand() % 5;

	std::cout << this->_type << " " << this->_name << " choses challenge "
			  << ScavTrap::_randomChallengePool[index] << std::endl;
}

void ScavTrap::_initializeRand(void) {
	if (ScavTrap::_isRandInitialized)
		return ;
	std::srand(std::time(NULL));
	ScavTrap::_isRandInitialized = true;
}

