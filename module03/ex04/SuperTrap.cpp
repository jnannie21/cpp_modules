//
// Created by jnannie on 12/21/20.
//

#include "SuperTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap(void) {

}

SuperTrap::SuperTrap(std::string name) {
	this->_type = "SuperTrap";
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &f) : ClapTrap(f) {

}

SuperTrap &SuperTrap::operator=(const SuperTrap &f) {
	ClapTrap::operator=(f);
	return (*this);
}

SuperTrap::~SuperTrap(void) {
	std::cout << this->_type << " " << this->_name << " is destructed." << std::endl;
}

void SuperTrap::rangedAttack(std::string const & target) const {
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) const {
	NinjaTrap::meleeAttack(target);
}
