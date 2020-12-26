//
// Created by jnannie on 12/24/20.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
	try
	{
		std::cout << "******** execution" << std::endl;

		Bureaucrat bureaucrat("Zafod Beeblebrox", 2);
		std::cout << bureaucrat << std::endl;

		std::cout << std::endl;
		ShrubberyCreationForm form1("home");
		std::cout << form1 << std::endl;

		bureaucrat.signForm(form1);

		form1.execute(bureaucrat);

		std::cout << std::endl;
		RobotomyRequestForm form2("wally");
		std::cout << form2 << std::endl;

		bureaucrat.signForm(form2);

		form2.execute(bureaucrat);

		std::cout << std::endl;
		PresidentialPardonForm form3("lex luthor");
		std::cout << form3 << std::endl;

		bureaucrat.signForm(form3);

		form3.execute(bureaucrat);

	}
	catch (std::exception &e)
	{
		std::cout << "exception in main: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "******** execute exception" << std::endl;

		Bureaucrat bureaucrat("Burea", 140);
		std::cout << bureaucrat << std::endl;

		std::cout << std::endl;
		ShrubberyCreationForm form1("home");
		std::cout << form1 << std::endl;

		bureaucrat.signForm(form1);

		form1.execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cout << "exception in main: " << e.what() << std::endl;
	}

	try
	{
		std::cout << std::endl << "******** sign exception" << std::endl;

		Bureaucrat bureaucrat("Burea", 150);
		std::cout << bureaucrat << std::endl;

		std::cout << std::endl;
		ShrubberyCreationForm form1("home");
		std::cout << form1 << std::endl;

		bureaucrat.signForm(form1);

		bureaucrat.executeForm(form1);

		form1.execute(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cout << "exception in main: " << e.what() << std::endl;
	}
}
