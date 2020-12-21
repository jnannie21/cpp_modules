//
// Created by Johnette Nannie on 12/17/20.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

class FragTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &f);
	~FragTrap(void);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void vaultHunterDotExe(std::string const & target);

private:
	std::string _type;
	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	std::string _name;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;

	static bool _isRandInitialized;
	static const std::string _randomAttackPool[5];
	static const unsigned int _randomAttackDamage[5];
	static const unsigned int _randomAttackEnergyCost;

	void _initializeRand(void);
};


#endif //FRAGTRAP_HPP
