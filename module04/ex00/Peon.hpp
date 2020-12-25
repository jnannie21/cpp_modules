//
// Created by jnannie on 12/22/20.
//

#ifndef PEON_HPP
#define PEON_HPP

#include "Victim.hpp"

class Peon : public Victim {
public:
	Peon(void);
	Peon(std::string name);
	Peon(Peon const &other);
	Peon &operator=(Peon const &other);
	virtual ~Peon(void);

	virtual void getPolymorphed(void) const;

};


#endif //PEON_HPP
