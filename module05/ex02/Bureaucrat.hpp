//
// Created by jnannie on 12/24/20.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat(std::string const &name, int grade)
		throw(GradeTooHighException, GradeTooLowException);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	std::string const &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form) const;

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
	int _grade;

};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif //BUREAUCRAT_HPP
