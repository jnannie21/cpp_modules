//
// Created by jnannie on 12/15/20.
//

#include "ZombieHorde.hpp"
#include <ctime>

const std::string ZombieHorde::_names[] = {
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

ZombieHorde::ZombieHorde(int n) {
	int name_index;
	ZombieType type;

	std::srand(std::time(NULL));
	this->_zombies = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		name_index = std::rand() % (sizeof(this->_names) / sizeof(std::string));
		this->_zombies[i].setName(this->_names[name_index]);
		type = (ZombieType)(std::rand() % NUMBER_OF_ZOMBIE_TYPES);
		this->_zombies[i].setType(type);
	}
	this->_n = n;
}

ZombieHorde::~ZombieHorde(void) {
	delete[] this->_zombies;
}

void ZombieHorde::announce(void) const {
	for (int i = 0; i < this->_n; i++)
		this->_zombies[i].announce();
}
