//
// Created by jnannie on 12/24/20.
//

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try
	{
		Bureaucrat bureaucrat("Burman", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try
	{
		Bureaucrat bureaucrat("Burman", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try
	{
		Bureaucrat bureaucrat("Burman", 2);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try
	{
		Bureaucrat bureaucrat("Burman", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
