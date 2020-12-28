//
// Created by jnannie on 12/28/20.
//

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void) {

	std::cout << "*********************************** vector" << std::endl;
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	std::vector<int>::iterator vecIt;

	vecIt = easyfind(vec, 3);
	if (vecIt == vec.end())
		std::cout << "element not found" << std::endl;
	else
		std::cout << *vecIt << std::endl;

	vecIt = easyfind(vec, 4);
	if (vecIt == vec.end())
		std::cout << "element not found" << std::endl;
	else
		std::cout << *vecIt << std::endl;


	std::cout << "*********************************** list" << std::endl;
	std::list<int> lst;

	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	std::list<int>::iterator lstIt;

	lstIt = easyfind(lst, 3);
	if (lstIt == lst.end())
		std::cout << "element not found" << std::endl;
	else
		std::cout << *lstIt << std::endl;

	lstIt = easyfind(lst, 4);
	if (lstIt == lst.end())
		std::cout << "element not found" << std::endl;
	else
		std::cout << *lstIt << std::endl;

	return 0;
}
