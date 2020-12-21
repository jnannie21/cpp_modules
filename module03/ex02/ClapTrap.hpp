//
// Created by jnannie on 12/20/20.
//

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <string>

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &f);
	ClapTrap &operator=(const ClapTrap &f);
	~ClapTrap(void);

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
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

private:
	void _initializeRand(void);

	static bool _isRandInitialized;
};


#endif //CLAPTRAP_HPP
