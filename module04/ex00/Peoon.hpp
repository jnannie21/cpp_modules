//
// Created by jnannie on 12/22/20.
//

#ifndef PEOON_HPP
#define PEOON_HPP

#include "Victim.hpp"

class Peoon : public Victim {
public:
	Peoon(void);
	Peoon(std::string name);
	Peoon(Peoon const &other);
	Peoon &operator=(Peoon const &other);
	virtual ~Peoon(void);

	virtual void getPolymorphed(void) const;

};

std::ostream &operator<<(std::ostream &stream, Peoon const &peoon);

#endif //PEOON_HPP
