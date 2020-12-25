//
// Created by jnannie on 12/24/20.
//

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try
	{
		Form form("form", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "--------------------" << std::endl;

	try
	{
		Form form("form", 1, 151);
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
		Form form1("budget1", 2, 140);
		std::cout << form1 << std::endl;
		bureaucrat.signForm(form1);
		std::cout << form1 << std::endl;

		std::cout << "--------------------" << std::endl;

		Form form2("budget2", 2, 140);
		bureaucrat.decrementGrade();
		bureaucrat.signForm(form2);
		std::cout << form2 << std::endl;

		form2.beSigned(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
