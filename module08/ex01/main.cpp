//
// Created by jnannie on 12/28/20.
//

#include "span.hpp"
#include <iostream>

int main()
{
	std::cout << "*********************************** subject" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "*********************************** not subject" << std::endl;

	try {
		Span sp = Span(10000);
		sp.generate();

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "*********************************** exceptions tests" << std::endl;

	try {
		Span sp = Span(1);
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	try {
		Span sp = Span(2);
		sp.addNumber(-5);
		sp.addNumber(3);

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;

		sp.addNumber(17);

	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	return 0;
}
