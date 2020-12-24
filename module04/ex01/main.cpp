//
// Created by jnannie on 12/22/20.
//

#include "Character.hpp"
#include "Enemy.hpp"
#include "AWeapon.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include <iostream>

int main()
{
	Character* me = new Character("me");

	std::cout << *me;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << "-------------------------" << std::endl;

	Enemy* c = new SuperMutant();

	me->attack(c);
	std::cout << *me;

	me->equip(pf);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	std::cout << *me;
	me->recoverAP();
	me->attack(c);

	me->attack(c);

	std::cout << "enemy hp is " << c->getHp() << std::endl;
	me->recoverAP();
	me->attack(c);
	std::cout << *me;

	std::cout << "-------------------------" << std::endl;

	Character* me2 = new Character("me2");
	std::cout << *me2;
	*me2 = *me;
	std::cout << *me2;

	std::cout << "-------------------------" << std::endl;

	delete pr;
	delete pf;
	delete me;
	delete me2;

	return 0;
}