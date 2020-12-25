//
// Created by jnannie on 12/24/20.
//

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unnamed"), _grade(150) {

}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();

	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();

	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) :
	_name(other._name),
	_grade(other._grade) {

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {

}

std::string const &Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("grade is too low");
}


std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}
