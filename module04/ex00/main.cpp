//
// Created by jnannie on 12/22/20.
//

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Peoon.hpp"
#include <iostream>

int main() {
	Sorcerer robert("Robert", "the Magnificent");

	Victim jim("Jimmy");
	Peon joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	std::cout << "---------------------------------" << std::endl;

	Peon qwe("qwe");
	std::cout << qwe;
	qwe = joe;
	std::cout << qwe;

	std::cout << "---------------------------------" << std::endl;

	Peon asd(joe);
	std::cout << asd;

	std::cout << "---------------------------------" << std::endl;

	Peoon john("John");
	std::cout << john;
	robert.polymorph(john);

	std::cout << "---------------------------------" << std::endl;

	return 0;
}