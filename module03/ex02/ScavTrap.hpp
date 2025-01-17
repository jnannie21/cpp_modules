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

private:

	static const std::string RANDOM_CHALLENGE_POOL[];
};


#endif //SCAVTRAP_HPP
