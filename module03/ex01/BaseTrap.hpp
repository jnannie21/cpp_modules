//
// Created by jnannie on 12/20/20.
//

#ifndef BASETRAP_HPP
#define BASETRAP_HPP


#include <string>

class BaseTrap {
public:
	BaseTrap(void);
	BaseTrap(const BaseTrap &f);
	BaseTrap &operator=(const BaseTrap &f);
	~BaseTrap(void);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
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


#endif //BASETRAP_HPP
