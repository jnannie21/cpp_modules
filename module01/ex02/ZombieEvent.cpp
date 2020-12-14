//
// Created by jnannie on 12/14/20.
//

#include "ZombieEvent.hpp"
#include <ctime>
#include <cstdlib>

const std::string ZombieEvent::_names[] = {
		"Liam",
		"Noah",
		"Oliver",
		"William",
		"Elijah",
		"James",
		"Benjamin",
		"Lucas",
		"Mason"
};

ZombieEvent::ZombieEvent(void) : _type(ZOMBIE_TYPE_NONE) {
	std::srand(std::time(NULL));
}

void ZombieEvent::setZombieType(ZombieType type) {
	this->_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name) const {
	Zombie *zombie = new Zombie(name, this->_type);

	return (zombie);
}

void ZombieEvent::randomChump(void) const {
	int index = std::rand() % (sizeof(this->_names) / sizeof(std::string));
	Zombie zombie(this->_names[index], this->_type);
	zombie.announce();
}
