//
// Created by jnannie on 12/14/20.
//

#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include "ZombieType.hpp"
#include "Zombie.hpp"
#include <string>

class ZombieEvent {
public:
	ZombieEvent(void);

	void setZombieType(ZombieType type);
	Zombie *newZombie(std::string name) const;
	void randomChump(void) const;

private:
	static const std::string _names[];
	ZombieType _type;
};

#endif //ZOMBIEEVENT_HPP
