//
// Created by jnannie on 12/24/20.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
	try
	{
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "hall");
		std::cout << *rrf << std::endl;
		delete rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("presidential pardon", "Joker");
		std::cout << *rrf << std::endl;
		delete rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;

		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("randomForm request", "randomTarget");
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << "exception in main: " << e.what() << std::endl;
	}
}
