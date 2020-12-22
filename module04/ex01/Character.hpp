//
// Created by jnannie on 12/22/20.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

class Character {
private:
	Character();

	std::string _name;
	int _ap;
	AWeapon *_weapon;

public:
	Character(std::string const & name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	~Character();
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string [...] getName() const;
};

#endif //CHARACTER_HPP
