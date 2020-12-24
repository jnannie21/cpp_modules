//
// Created by jnannie on 12/23/20.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter {
private:
	std::string _name;
	AMateria *_inventory[4];

public:
	Character();
	Character(std::string const &name);
	Character(Character const &other);
	Character &operator=(Character const &other);
	virtual ~Character();

	AMateria *getMateria(int idx);
	virtual std::string const &getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

};


#endif //CHARACTER_HPP
