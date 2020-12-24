//
// Created by jnannie on 12/24/20.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Burman"), _grade(150) {

}

Bureaucrat::Bureaucrat(std::string const &name, int grade) throw(GradeTooHighException, GradeTooLowException) : _name(name) {
	if (grade < 0)
		throw Bureaucrat::GradeTooHighException();


	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) {

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {

}

Bureaucrat::~Bureaucrat() {

}

std::string const &Bureaucrat::getName() const {
	return (this->_name);
}
int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::increment() {
	if (this->_grade == 0)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}


virtual const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("grade is too high");
}

virtual const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("grade is too low");
}