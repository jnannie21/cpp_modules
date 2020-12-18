//
// Created by Johnette Nannie on 12/17/20.
//

#include "FragTrap.hpp"
#include <iostream>

const std::string FragTrap::_randomAttacksPool[] = {
	"Bite",
	"Stab with knife",
	"Loud shout",
	"Bow",
	"Kick"
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
	_armorDamageReduction(5) {
	std::srand(std::time(NULL));
	std::cout << "FR4G-TP" << this->_name << "created" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FR4G-TP" << this->_name << "destructed" << std::endl;
}

void FragTrap::rangedAttack(std::string const &target) {
	std::cout << "FR4G-TP" << this->_name << " attacks " << target << " with ranged attack, causing " << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target) {
	std::cout << "FR4G-TP" << this->_name << " attacks " << target << " with melee attack, causing " << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	unsigned int damage = 0;

	if (amount > this->_armorDamageReduction)
		damage = amount - this->_armorDamageReduction;
	if (this->_hitPoints <= damage)
	{
		this->~FragTrap();
		return ;
	}
	this->_hitPoints -= damage;
	std::cout << "FR4G-TP" << this->_name << " takes damage of " << damage << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount
		|| this->_hitPoints + amount > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else
		this->_hitPoints += amount;
	std::cout << "FR4G-TP" << this->_name << " is repaired by " << amount << " points!" << std::endl;
}

void FragTrap::vaultHunterDotExe(std::string const &target) {
	int index = std::rand() % 5;


//	std::cout << "FR4G-TP <name> attacks <target> at range, causing <damage> points of damage!" << std::endl;
}
