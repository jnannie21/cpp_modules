//
// Created by jnannie on 12/15/20.
//

#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde {
public:
	ZombieHorde(int n);
	void announce(void);

private:
	static const std::string _names[];

	Zombie *_zombies;
	int _n;
};


#endif //ZOMBIEHORDE_HPP
