//
// Created by jnannie on 12/20/20.
//

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &f);
	ScavTrap &operator=(const ScavTrap &f);
	~ScavTrap(void);

	void challengeNewcomer(void);

private:
	ScavTrap(void);

	static const std::string _randomChallengePool[];
};


#endif //SCAVTRAP_HPP
