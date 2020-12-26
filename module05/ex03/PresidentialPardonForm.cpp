//
// Created by jnannie on 12/26/20.
//

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) :
	Form(other) {

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	if (this == &other)
		return (*this);

	Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	throw(GradeTooHighException, GradeTooLowException) :
		Form("PresidentialPardonForm", 25, 5) {
	this->setTarget(target);
}

void PresidentialPardonForm::executeConcrete() const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
