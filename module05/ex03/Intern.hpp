//
// Created by jnannie on 12/26/20.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include <string>

class Intern {
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	virtual ~Intern();

	static Form *makeForm(std::string const &formName, std::string const &target);

	typedef Form *(*t_createForm)(std::string const &target);

	static int const numberOfForms = 3;

	class FormNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	static Form *makeShrubberyCreationForm(std::string const &target);
	static Form *makeRobotomyRequestForm(std::string const &target);
	static Form *makePresidentialPardonForm(std::string const &target);

	static std::string const _formNames[numberOfForms];
	static t_createForm const _formCreators[numberOfForms];
};


#endif //INTERN_HPP
