//
// Created by Johnette Nannie on 12/17/20.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &f);
	~FragTrap(void);

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
	void vaultHunterDotExe(std::string const & target);

private:
	static const std::string RANDOM_ATTACK_POOL[];
	static const unsigned int RANDOM_ATTACK_DAMAGE[];
	static const unsigned int RANDOM_ATTACK_ENERGY_COST = 25;
};


#endif //FRAGTRAP_HPP
