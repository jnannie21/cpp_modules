//
// Created by jnannie on 12/24/20.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat::Bureaucrat(std::string const &name, int grade) throw(GradeTooHighException, GradeTooLowException);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &other);

	std::string const &getName() const;
	int getGrade() const;
	void increment();
	void decrement();

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


#endif //BUREAUCRAT_HPP
