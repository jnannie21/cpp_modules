#include <iostream>
#include "Pony.hpp"

void ponyOnTheHeap(void) {
	Pony *pony = new Pony();
	std::string name("heap_pony");

	pony->walk();
	pony->stop();
	pony->sayName();
	pony->changeName(name);
	pony->sayName();
	pony->sayColor();
	pony->changeColor(Pony::COLOR_BLUE);
	pony->sayColor();
	delete pony;
}

void ponyOnTheStack(void) {
	Pony pony;
	std::string name("stack_pony");

	pony.walk();
	pony.stop();
	pony.sayName();
	pony.changeName(name);
	pony.sayName();
	pony.sayColor();
	pony.changeColor(Pony::COLOR_RED);
	pony.sayColor();
}

int main() {
	std::cout << "Pony on the heap:" << std::endl;
	ponyOnTheHeap();
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Pony on the stack:" << std::endl;
	ponyOnTheStack();
	return 0;
}
