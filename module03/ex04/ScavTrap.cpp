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

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
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

ScavTrap::ScavTrap(const ScavTrap &f) : ClapTrap(f) {

}

ScavTrap &ScavTrap::operator=(const ScavTrap &f) {
	ClapTrap::operator=(f);
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << this->_type << " " << this->_name << " is destructed." << std::endl;
}

void ScavTrap::challengeNewcomer(void) {
	int index = std::rand() % 5;

	std::cout << this->_type << " " << this->_name << " choses challenge "
			  << ScavTrap::_randomChallengePool[index] << std::endl;
}
