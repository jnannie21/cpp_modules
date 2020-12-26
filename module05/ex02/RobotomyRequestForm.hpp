//
// Created by jnannie on 12/25/20.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string const &target)
		throw(GradeTooHighException, GradeTooLowException);

	virtual void executeConcrete() const;

};


#endif //ROBOTOMYREQUESTFORM_HPP
