//
// Created by jnannie on 12/22/20.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Enemy.hpp"
#include "AWeapon.hpp"
#include <string>

class Character {
private:
	std::string _name;
	int _ap;
	AWeapon *_weapon;

public:
	Character();
	Character(std::string const & name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	~Character();

	void recoverAP();
	void equip(AWeapon *weapon);
	void attack(Enemy *enemy);
	std::string const &getName() const;
	int getAp() const;
	AWeapon *getWeapon() const;
};

std::ostream &operator<<(std::ostream &stream, Character const &character);

#endif //CHARACTER_HPP
