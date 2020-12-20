//
// Created by jnannie on 12/20/20.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "BaseTrap.hpp"
#include <string>

class ScavTrap : public BaseTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &f);
	ScavTrap &operator=(const ScavTrap &f);
	~ScavTrap(void);

	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void challengeNewcomer(void);

private:
	ScavTrap(void);

	static const std::string _randomChallengePool[];
};


#endif //SCAVTRAP_HPP
