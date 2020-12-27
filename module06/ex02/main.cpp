//
// Created by jnannie on 12/27/20.
//

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base *generate(void) {
	int r = rand() % 3;
	if (r == 0)
	{
		std::cout << "generated A" << std::endl;
		return static_cast<Base *>(new A());
	}
	else if (r == 1)
	{
		std::cout << "generated B" << std::endl;
		return static_cast<Base *>(new B());
	}
	else
	{
		std::cout << "generated C" << std::endl;
		return static_cast<Base *>(new C());
	}
}

void identify_from_pointer(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown type" << std::endl;
}

void identify_from_reference(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (std::exception& e) {
		try {
			B &b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)b;
		} catch (std::exception& e) {
			try {
				C &c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)c;
			} catch (std::exception& e) {
				std::cout << "unknown type" << std::endl;
			}
		}
	}
}


int main(void) {
	srand(time(NULL));

	Base *p;

	std::cout << "************************** identify from pointer" << std::endl;

	p = generate();
	identify_from_pointer(p);
	delete p;
	p = generate();
	identify_from_pointer(p);
	delete p;
	p = generate();
	identify_from_pointer(p);
	delete p;

	std::cout << "************************** identify from reference" << std::endl;

	p = generate();
	identify_from_reference(*p);
	delete p;
	p = generate();
	identify_from_reference(*p);
	delete p;
	p = generate();
	identify_from_reference(*p);
	delete p;

	return 0;
}
