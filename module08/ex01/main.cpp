//
// Created by jnannie on 12/28/20.
//

#include "Span.hpp"
#include <iostream>

int main()
{
	std::cout << "*********************************** vector" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}
