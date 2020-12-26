//
// Created by jnannie on 12/24/20.
//

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <stdexcept>

class Form {
public:
	Form();
	Form(Form const &other);
	Form(std::string const &name, int gradeToSign, int gradeToExecute)
		throw(GradeTooHighException, GradeTooLowException);
	~Form();

	Form &operator=(Form const &other);

	std::string const &getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat const &bureaucrat) throw(GradeTooHighException);
	bool isSigned() const;
	std::string const &getTarget() const;
	void setTarget(std::string const &target);

	virtual void checkBeforeExecute(Bureaucrat const &executor) const
	throw(NotSignedException, GradeTooHighException);
	virtual void execute(Bureaucrat const &executor) const
		throw(NotSignedException, GradeTooHighException);
	virtual void executeConcrete() const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
	std::string _target;

};

std::ostream &operator<<(std::ostream &stream, Form const &form);


#endif //FORM_HPP
