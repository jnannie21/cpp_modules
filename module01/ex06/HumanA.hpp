//
// Created by jnannie on 12/15/20.
//

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(const std::string &name, Weapon &weapon);
	void attack(void) const;

private:
	std::string _name;
	Weapon &_weapon;

};


#endif //HUMANA_HPP
