//
// Created by jnannie on 12/26/20.
//

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

std::string const Intern::_formNames[Intern::numberOfForms] = {
		"shrubbery creation",
		"presidential pardon",
		"robotomy request"
};

Intern::t_createForm const Intern::_formCreators[Intern::numberOfForms] = {
	makeShrubberyCreationForm,
	makePresidentialPardonForm,
	makeRobotomyRequestForm

};

Intern::Intern() {

}

Intern::Intern(Intern const &other) {
	(void)other;
}

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	return (*this);
}

Intern::~Intern() {

}

Form *Intern::makeForm(std::string const &formName, std::string const &target) {
	for (int i = 0; i < Intern::numberOfForms; i++)
	{
		if (Intern::_formNames[i] == formName)
		{
			Form *form = Intern::_formCreators[i](target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "form " << formName << " not found" << std::endl;
	throw FormNotFoundException();
}

Form *Intern::makeShrubberyCreationForm(std::string const &target) {
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyRequestForm(std::string const &target) {
	return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialPardonForm(std::string const &target) {
	return (new PresidentialPardonForm(target));
}

const char *Intern::FormNotFoundException::what() const throw() {
	return ("form not found");
}
