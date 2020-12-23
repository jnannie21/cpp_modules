//
// Created by jnannie on 12/23/20.
//

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria {
private:
	std::string _type;
	unsigned int _xp;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &other);
	AMateria &operator=(AMateria const &other);
	virtual ~AMateria();

	std::string const &getType() const;
	unsigned int getXP() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif //AMATERIA_HPP
