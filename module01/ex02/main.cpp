//
// Created by jnannie on 12/14/20.
//

#include "ZombieType.hpp"
#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void) {
	ZombieEvent event;
	Zombie *zombie;

	event.setZombieType(ZOMBIE_TYPE_NINJA);
	zombie = event.newZombie("Jnannie");
	zombie->announce();
	delete zombie;

	event.setZombieType(ZOMBIE_TYPE_HOMER);
	event.randomChump();
	event.randomChump();

	event.setZombieType(ZOMBIE_TYPE_HAWKING);
	event.randomChump();
	event.randomChump();
	return (0);
}
