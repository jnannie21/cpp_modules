//
// Created by jnannie on 12/23/20.
//

#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine {
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &other);
	AssaultTerminator &operator=(AssaultTerminator const &other);
	virtual ~AssaultTerminator();

	virtual ISpaceMarine *clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;

};


#endif //ASSAULTTERMINATOR_HPP
