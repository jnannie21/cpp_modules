//
// Created by Johnette Nannie on 12/17/20.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

class FragTrap {
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &f);
	~FragTrap(void);

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void vaultHunterDotExe(std::string const & target);

private:
	FragTrap(void);

	void _initializeRand(void);

	static bool _isRandInitialized;
	static const std::string _randomAttackPool[];
	static const unsigned int _randomAttackDamage[];

	unsigned int _hitPoints;
	unsigned int _maxHitPoints;
	unsigned int _energyPoints;
	unsigned int _maxEnergyPoints;
	unsigned int _level;
	std::string _name;
	unsigned int _meleeAttackDamage;
	unsigned int _rangedAttackDamage;
	unsigned int _armorDamageReduction;
	unsigned int _randomAttackEnergyCost;

};


#endif //FRAGTRAP_HPP
