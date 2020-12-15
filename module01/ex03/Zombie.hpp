//
// Created by jnannie on 12/14/20.
//

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "ZombieType.hpp"
#include <string>

class Zombie {
public:
	Zombie(void);
	~Zombie(void);
	Zombie(std::string name, ZombieType type);

	void setName(std::string name);
	void setType(ZombieType type);
	void announce(void) const;

private:
	static const std::string _type_names[];

	std::string _name;
	ZombieType _type;

};

#endif //ZOMBIE_HPP
