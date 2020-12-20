//
// Created by Johnette Nannie on 12/17/20.
//

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &f);
	~FragTrap(void);

	void vaultHunterDotExe(std::string const & target);

private:
	FragTrap(void);

	static const std::string _randomAttackPool[5];
	static const unsigned int _randomAttackDamage[5];
	static const unsigned int _randomAttackEnergyCost;
};


#endif //FRAGTRAP_HPP
