//
// Created by jnannie on 12/23/20.
//

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(Ice const &other);
	Ice &operator=(Ice const &other);
	virtual ~Ice();

	virtual AMateria* clone() const;
	virtual void use(ICharacter &target);

};


#endif //ICE_HPP
