//
// Created by jnannie on 12/22/20.
//

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon
{
private:
	AWeapon();

	std::string _name;
	int _damage;
	int _apCost;

public:
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &other);
	AWeapon &operator=(AWeapon const &other);
	~AWeapon();
	std::string [...] getName() const;
	int getAPCost() const;
	int getDamage() const;
	[...] void attack() const = 0;
};

#endif //AWEAPON_HPP
