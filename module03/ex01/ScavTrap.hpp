//
// Created by jnannie on 12/20/20.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>

class ScavTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &f);
	ScavTrap &operator=(const ScavTrap &f);
	~ScavTrap(void);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void challengeNewcomer(void);

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
	static const std::string _randomChallengePool[];

	void _initializeRand(void);
};


#endif //SCAVTRAP_HPP
