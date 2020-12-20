//
// Created by jnannie on 12/20/20.
//

#include "ScavTrap.hpp"
#include <iostream>

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
	BaseTrap::operator=(f);
	return (*this);
}

ScavTrap::~ScavTrap(void) {

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
