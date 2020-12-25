//
// Created by jnannie on 12/25/20.
//

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) :
	Form(other) {

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	if (this == &other)
		return (*this);

	Form::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	throw(GradeTooHighException, GradeTooLowException) :
	Form("RobotomyRequestForm", 72, 45) {
	this->setTarget(target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
	throw(NotSignedException, GradeTooHighException) {
	if (!this->isSigned())
		throw NotSignedException();

	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooHighException();

	std::cout << "* drilling noises * " << this->getTarget()
			  << " has been robotomized successfully 50% of the time" << std::endl;
}

const char *RobotomyRequestForm::NotSignedException::what() const throw() {
	return ("RobotomyRequestForm not signed");
}
