//
// Created by jnannie on 12/25/20.
//

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

class ShrubberyCreationForm : public Form {
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(std::string const &target)
		throw(GradeTooHighException, GradeTooLowException);

	virtual void executeConcrete() const;

};


#endif //SHRUBBERYCREATIONFORM_HPP
