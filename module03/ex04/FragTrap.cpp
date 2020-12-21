//
// Created by Johnette Nannie on 12/17/20.
//

#include "FragTrap.hpp"
#include <iostream>

const std::string FragTrap::RANDOM_ATTACK_POOL[] = {
	"Bite",
	"Stab with knife",
	"Loud shout",
	"Bow",
	"Kick"
};

const unsigned int FragTrap::RANDOM_ATTACK_DAMAGE[] = {
	35,
	45,
	15,
	25,
	15
};

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
	std::cout << "FragTrap is destructed." << std::endl;
}

void FragTrap::rangedAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with ranged attack, causing "
			  << this->_rangedAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::meleeAttack(std::string const &target) const {
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with melee attack, causing "
			  << this->_meleeAttackDamage << " points of damage!" << std::endl;
}

void FragTrap::vaultHunterDotExe(std::string const &target) {
	int index = std::rand() % 5;

	if (this->_energyPoints < FragTrap::RANDOM_ATTACK_ENERGY_COST)
	{
		std::cout << this->_type << " " << this->_name << " out of energy." << std::endl;
		return ;
	}
	else
		this->_energyPoints -= FragTrap::RANDOM_ATTACK_ENERGY_COST;
	std::cout << this->_type << " " << this->_name << " attacks " << target << " with "
			<< FragTrap::RANDOM_ATTACK_POOL[index] << " attack, causing "
			<< FragTrap::RANDOM_ATTACK_DAMAGE[index] << " points of damage!" << std::endl;
}
