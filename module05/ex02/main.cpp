//
// Created by jnannie on 12/24/20.
//

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main() {
	try
	{
		Bureaucrat bureaucrat("Burman", 2);
		std::cout << bureaucrat << std::endl;
		ShrubberyCreationForm form1("home");
		std::cout << form1 << std::endl;
		bureaucrat.signForm(form1);
		std::cout << form1 << std::endl;

		form1.execute(bureaucrat);

//		std::cout << "--------------------" << std::endl;
//
//		Form form2("budget2", 2, 140);
//		bureaucrat.decrementGrade();
//		bureaucrat.signForm(form2);
//		std::cout << form2 << std::endl;
//
//		form2.beSigned(bureaucrat);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
