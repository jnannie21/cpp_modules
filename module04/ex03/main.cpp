//
// Created by jnannie on 12/23/20.
//

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "------------------------------" << std::endl;

	tmp = src->createMateria("qwe");
	std::cout << tmp << std::endl;

	me->equip(tmp);

	std::cout << "------------------------------ character assignment operator test" << std::endl;

	Character* otherMe = new Character("otherMe");
	std::cout << otherMe->getName() << std::endl;
	*otherMe = *(Character*)me;
	std::cout << otherMe->getName() << std::endl;

	otherMe->use(0, *me);
	otherMe->use(1, *me);
	otherMe->use(2, *me);

	otherMe->equip(src->createMateria("ice"));
	otherMe->equip(src->createMateria("cure"));
	tmp = src->createMateria("ice");
	otherMe->equip(tmp);
	delete tmp;

	std::cout << "------------equipment test" << std::endl;

	otherMe->use(2, *me);
	otherMe->use(3, *me);
	otherMe->use(4, *me);

	std::cout << "------------materiaSource assignment operator test" << std::endl;

	MateriaSource* src2 = new MateriaSource;
	*src2 = *(MateriaSource*)src;

	tmp = otherMe->getMateria(3);
	otherMe->unequip(3);
	otherMe->use(3, *me);
	delete tmp;

	tmp = src2->createMateria("ice");
	otherMe->equip(tmp);
	otherMe->use(3, *me);

	std::cout << tmp->getXP() << std::endl;

	delete otherMe;
	delete bob;
	delete me;
	delete src;
	delete src2;

	return 0;
}
