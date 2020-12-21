//
// Created by Johnette Nannie on 12/17/20.
//

#include "FragTrap.hpp"
#include <iostream>

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

const unsigned int FragTrap::_randomAttackEnergyCost = 25;

FragTrap::FragTrap(void) {

}

FragTrap::FragTrap(std::string name) {
	this->_type = "FragTrap";
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

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f) {

}

FragTrap &FragTrap::operator=(const FragTrap &f) {
	ClapTrap::operator=(f);
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << this->_type << " " << this->_name << " is destructed." << std::endl;
}

void FragTrap::vaultHunterDotExe(std::string const &target) {
	int index = std::rand() % 5;

	if (this->_energyPoints < FragTrap::_randomAttackEnergyCost)
	{
		std::cout << this->_type << " " << this->_name << " out of energy." << std::endl;
		return ;
	}
	else
		this->_energyPoints -= FragTrap::_randomAttackEnergyCost;
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with "
			<< FragTrap::_randomAttackPool[index] << " attack, causing "
			<< FragTrap::_randomAttackDamage[index] << " points of damage!" << std::endl;
}
