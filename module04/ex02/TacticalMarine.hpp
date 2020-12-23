//
// Created by jnannie on 12/23/20.
//

#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &other);
	TacticalMarine &operator=(TacticalMarine const &other);
	virtual ~TacticalMarine();

	virtual ISpaceMarine *clone() const;
	virtual void battleCry() const;
	virtual void rangedAttack() const;
	virtual void meleeAttack() const;

};


#endif //TACTICALMARINE_HPP
