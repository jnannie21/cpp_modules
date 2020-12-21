//
// Created by Johnette Nannie on 12/17/20.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &f);
	~FragTrap(void);

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;

	void vaultHunterDotExe(std::string const & target);

protected:
	static const int HIT_POINTS = 100;
	static const int MAX_HIT_POINTS = 100;
	static const int ENERGY_POINTS = 100;
	static const int MAX_ENERGY_POINTS = 100;
	static const int LEVEL = 1;
	static const int MELEE_ATTACK_DAMAGE = 30;
	static const int RANGED_ATTACK_DAMAGE = 20;
	static const int ARMOR_DAMAGE_REDUCTION = 5;

private:
	static const std::string RANDOM_ATTACK_POOL[];
	static const unsigned int RANDOM_ATTACK_DAMAGE[];
	static const unsigned int RANDOM_ATTACK_ENERGY_COST = 25;
};


#endif //FRAGTRAP_HPP
