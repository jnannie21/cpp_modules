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
	this->_hitPoints = HIT_POINTS;
	this->_maxHitPoints = MAX_HIT_POINTS;
	this->_energyPoints = ENERGY_POINTS;
	this->_maxEnergyPoints = MAX_ENERGY_POINTS;
	this->_level = LEVEL;
	this->_name = name;
	this->_meleeAttackDamage = MELEE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = ARMOR_DAMAGE_REDUCTION;

	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &f) : ClapTrap(f) {

}

ScavTrap &ScavTrap::operator=(const ScavTrap &f) {
	ClapTrap::operator=(f);
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap is destructed." << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " uses ranged attack on " << target << " and causes "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " uses ranged attack on " << target << " and causes "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void ScavTrap::challengeNewcomer(void) {
	int index = std::rand() % 5;

	std::cout << this->_type << " " << this->_name << " choses challenge "
			  << ScavTrap::_randomChallengePool[index] << std::endl;
}
