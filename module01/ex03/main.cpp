#include <iostream>
#include "ZombieHorde.hpp"

int main() {
	Zombie zombie;
	zombie.announce();

	ZombieHorde zombie_horde(5);
	zombie_horde.announce();

	return (0);
}
