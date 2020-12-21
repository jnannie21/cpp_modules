//
// Created by jnannie on 12/20/20.
//

#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(void) {

}

NinjaTrap::NinjaTrap(std::string name) {
	this->_type = "NinjaTrap";
	this->_hitPoints = 60;
	this->_maxHitPoints = 60;
	this->_energyPoints = 120;
	this->_maxEnergyPoints = 120;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = 60;
	this->_rangedAttackDamage = 5;
	this->_armorDamageReduction = 0;
	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &f) : ClapTrap(f) {

}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &f) {
	ClapTrap::operator=(f);
	return (*this);
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << this->_type << " " << this->_name << " is destructed." << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with ranged attack, causing "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with melee attack, causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void NinjaTrap::ninjaShoebox(ClapTrap &trap) {
	std::cout << this->_type << " " << this->_name << " attacks " << trap.getType() << " " << trap.getName() << " with ninjaShoebox attack, causing... no damage at all..." << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &trap) {
	std::cout << this->_type << " " << this->_name << " attacks " << trap.getType() << " " << trap.getName() << " with ninjaShoebox attack, causing... no damage at all..." << std::endl;
}

void NinjaTrap::ninjaShoebox(ScavTrap &trap) {
	std::cout << this->_type << " " << this->_name << " attacks " << trap.getType() << " " << trap.getName() << " with ninjaShoebox attack, causing... no damage at all..." << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &trap) {
	std::cout << this->_type << " " << this->_name << " attacks " << trap.getType() << " " << trap.getName() << " with ninjaShoebox attack, causing... no damage at all..." << std::endl;
}
