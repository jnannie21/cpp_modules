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
	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;

};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);


#endif //FORM_HPP
