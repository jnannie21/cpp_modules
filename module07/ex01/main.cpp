//
// Created by jnannie on 12/27/20.
//

#include "iter.hpp"
#include <iostream>


struct Data {
	std::string s;
};

void doubleInt(int const &i) {
	std::cout << i * 2 << " ";
}

void printData(Data const &el) {
	std::cout << el.s << " ";
}

int main(void) {
	int intArr[] = {1, 2, 3};
	Data dataArr[] = {{"hello"}, {"hi"}, {"privet"}};

	iter(intArr, 3, doubleInt);
	std::cout << std::endl;

	iter(dataArr, 3, printData);
	std::cout << std::endl;

	return 0;
}
