//
// Created by jnannie on 12/20/20.
//

#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap(void) {

}

NinjaTrap::NinjaTrap(std::string name) {
	this->_type = "NinjaTrap";
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

NinjaTrap::NinjaTrap(const NinjaTrap &f) : ClapTrap(f) {

}

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &f) {
	ClapTrap::operator=(f);
	return (*this);
}

NinjaTrap::~NinjaTrap(void) {
	std::cout << this->_type << " " << this->_name << " is destructed." << std::endl;
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
