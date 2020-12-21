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
	this->_hitPoints = FragTrap::HIT_POINTS;
	this->_maxHitPoints = FragTrap::MAX_HIT_POINTS;
	this->_energyPoints = NinjaTrap::ENERGY_POINTS;
	this->_maxEnergyPoints = NinjaTrap::MAX_ENERGY_POINTS;
	this->_level = 1;
	this->_name = name;
	this->_meleeAttackDamage = NinjaTrap::MELEE_ATTACK_DAMAGE;
	this->_rangedAttackDamage = FragTrap::RANGED_ATTACK_DAMAGE;
	this->_armorDamageReduction = FragTrap::ARMOR_DAMAGE_REDUCTION;
	std::cout << this->_type << " " << this->_name << " is created." << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &f) : ClapTrap(f) {

}

SuperTrap &SuperTrap::operator=(const SuperTrap &f) {
	ClapTrap::operator=(f);
	return (*this);
}

SuperTrap::~SuperTrap(void) {
	std::cout << "SuperTrap is destructed." << std::endl;
}

void SuperTrap::rangedAttack(std::string const & target) const {
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target) const {
	NinjaTrap::meleeAttack(target);
}
