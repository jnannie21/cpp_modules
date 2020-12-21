//
// Created by jnannie on 12/20/20.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &f);
	ScavTrap &operator=(const ScavTrap &f);
	~ScavTrap(void);

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;

	void challengeNewcomer(void);

protected:
	static const int HIT_POINTS = 100;
	static const int MAX_HIT_POINTS = 100;
	static const int ENERGY_POINTS = 50;
	static const int MAX_ENERGY_POINTS = 50;
	static const int LEVEL = 1;
	static const int MELEE_ATTACK_DAMAGE = 20;
	static const int RANGED_ATTACK_DAMAGE = 15;
	static const int ARMOR_DAMAGE_REDUCTION = 3;

private:
	static const std::string RANDOM_CHALLENGE_POOL[];
};


#endif //SCAVTRAP_HPP
