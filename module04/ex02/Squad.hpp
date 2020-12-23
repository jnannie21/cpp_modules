//
// Created by jnannie on 12/23/20.
//

#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
public:
	Squad();
	Squad(Squad const &other);
	Squad &operator=(Squad const &other);
	virtual ~Squad();

	virtual int getCount() const;
	virtual ISpaceMarine *getUnit(int) const;
	virtual int push(ISpaceMarine *);

private:
	int _count;
	ISpaceMarine **_units;

};


#endif //SQUAD_HPP
