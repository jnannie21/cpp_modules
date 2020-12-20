//
// Created by jnannie on 12/20/20.
//

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class NinjaTrap : public ClapTrap {
public:
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &f);
	NinjaTrap &operator=(const NinjaTrap &f);
	~NinjaTrap(void);

	void ninjaShoebox(ClapTrap &trap);
	void ninjaShoebox(FragTrap &trap);
	void ninjaShoebox(ScavTrap &trap);
	void ninjaShoebox(NinjaTrap &trap);

private:
	NinjaTrap(void);
};


#endif //NINJATRAP_HPP
