//
// Created by jnannie on 12/26/20.
//

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include <string>

class PresidentialPardonForm : public Form {
public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	~PresidentialPardonForm();

	PresidentialPardonForm(std::string const &target)
	throw(GradeTooHighException, GradeTooLowException);

	virtual void executeConcrete() const;

};


#endif //PRESIDENTIALPARDONFORM_HPP
