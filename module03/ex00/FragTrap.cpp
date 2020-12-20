//
// Created by Johnette Nannie on 12/17/20.
//

#include "FragTrap.hpp"
#include <iostream>

bool FragTrap::_isRandInitialized = false;

const std::string FragTrap::_randomAttackPool[] = {
	"Bite",
	"Stab with knife",
	"Loud shout",
	"Bow",
	"Kick"
};

const unsigned int FragTrap::_randomAttackDamage[] = {
	35,
	45,
	15,
	25,
	15
};

FragTrap::FragTrap(void) {

}

FragTrap::FragTrap(std::string name) :
	_hitPoints(100),
	_maxHitPoints(100),
	_energyPoints(100),
	_maxEnergyPoints(100),
	_level (1),
	_name(name),
	_meleeAttackDamage(30),
	_rangedAttackDamage(20),
	_armorDamageReduction(5),
	_randomAttackEnergyCost(25) {
	this->_initializeRand();
	std::cout << "FR4G-TP " << this->_name << " is created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &f) {
	this->_initializeRand();
	*this = f;
	std::cout << "FR4G-TP " << this->_name << " is created." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &f) {
	this->_hitPoints = f._hitPoints;
	this->_maxHitPoints = f._maxHitPoints;
	this->_energyPoints = f._energyPoints;
	this->_maxEnergyPoints = f._maxEnergyPoints;
	this->_level = f._level;
	this->_name = f._name;
	this->_meleeAttackDamage = f._meleeAttackDamage;
	this->_rangedAttackDamage = f._rangedAttackDamage;
	this->_armorDamageReduction = f._armorDamageReduction;
	this->_randomAttackEnergyCost = f._randomAttackEnergyCost;
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "FR4G-TP " << this->_name << "destructed." << std::endl;
}

void FragTrap::rangedAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with ranged attack, causing "
			<< this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target) {
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with melee attack, causing "
			<< this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	unsigned int damage = 0;

	if (amount > this->_armorDamageReduction)
		damage = amount - this->_armorDamageReduction;
	if (this->_hitPoints < damage)
		damage = this->_hitPoints;
	this->_hitPoints -= damage;
	std::cout << "FR4G-TP " << this->_name << " takes " << damage << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if ((this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount)
		|| (this->_hitPoints + amount > this->_maxHitPoints))
		amount = this->_maxHitPoints - this->_hitPoints;
	this->_hitPoints += amount;
	std::cout << "FR4G-TP " << this->_name << " is repaired by " << amount << " points." << std::endl;
}

void FragTrap::vaultHunterDotExe(std::string const &target) {
	int index = std::rand() % 5;

	if (this->_energyPoints < this->_randomAttackEnergyCost)
	{
		std::cout << "FR4G-TP " << this->_name << " out of energy." << std::endl;
		return ;
	}
	else
		this->_energyPoints -= this->_randomAttackEnergyCost;
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << " with "
			<< FragTrap::_randomAttackPool[index] << " attack, causing "
			<< FragTrap::_randomAttackDamage[index] << " points of damage!" << std::endl;
}

void FragTrap::_initializeRand(void) {
	if (FragTrap::_isRandInitialized)
		return ;
	std::srand(std::time(NULL));
	FragTrap::_isRandInitialized = true;
}
