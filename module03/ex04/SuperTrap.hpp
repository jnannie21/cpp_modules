//
// Created by jnannie on 12/21/20.
//

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>

class SuperTrap : public FragTrap, public NinjaTrap {
public:
	SuperTrap(void);
	SuperTrap(std::string name);
	SuperTrap(const SuperTrap &f);
	SuperTrap &operator=(const SuperTrap &f);
	~SuperTrap(void);

	void rangedAttack(std::string const & target) const;
	void meleeAttack(std::string const & target) const;
};


#endif //SUPERTRAP_HPP
