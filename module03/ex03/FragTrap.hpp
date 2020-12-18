//
// Created by Johnette Nannie on 12/17/20.
//

#ifndef MODULE03_FRAGTRAP_HPP
#define MODULE03_FRAGTRAP_HPP

#include <string>

class FragTrap {
public:
	FragTrap(std::string name);
	~FragTrap(void);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &f);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaultHunterDotExe(std::string const & target);

private:
	FragTrap(void);

	static const std::string _randomAttacksPool[];
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	std::string _name;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;
};


#endif //MODULE03_FRAGTRAP_HPP
