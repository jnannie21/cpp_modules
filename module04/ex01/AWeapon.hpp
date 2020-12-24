//
// Created by jnannie on 12/22/20.
//

#ifndef AWEAPON_HPP
#define AWEAPON_HPP

#include <string>

class AWeapon
{
private:
	std::string _name;
	int _apCost;
	int _damage;

public:
	AWeapon();
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const &other);
	AWeapon &operator=(AWeapon const &other);
	virtual ~AWeapon();

	std::string const &getName() const;
	int getApCost() const;
	int getDamage() const;

	virtual void attack() const = 0;
};

#endif //AWEAPON_HPP
