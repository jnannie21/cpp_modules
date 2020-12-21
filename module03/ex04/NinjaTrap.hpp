//
// Created by jnannie on 12/20/20.
//

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class NinjaTrap : public virtual ClapTrap {
public:
	NinjaTrap(void);
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &f);
	NinjaTrap &operator=(const NinjaTrap &f);
	~NinjaTrap(void);

	void ninjaShoebox(ClapTrap &trap);
	void ninjaShoebox(FragTrap &trap);
	void ninjaShoebox(ScavTrap &trap);
	void ninjaShoebox(NinjaTrap &trap);

protected:
	static const int HIT_POINTS = 60;
	static const int MAX_HIT_POINTS = 60;
	static const int ENERGY_POINTS = 120;
	static const int MAX_ENERGY_POINTS = 120;
	static const int LEVEL = 1;
	static const int MELEE_ATTACK_DAMAGE = 60;
	static const int RANGED_ATTACK_DAMAGE = 5;
	static const int ARMOR_DAMAGE_REDUCTION = 0;
};


#endif //NINJATRAP_HPP
