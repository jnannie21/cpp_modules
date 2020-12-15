//
// Created by jnannie on 12/15/20.
//

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
public:
	HumanB(const std::string &name);
	void attack(void) const;
	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon *_weapon;

};


#endif //HUMANB_HPP
