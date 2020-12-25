//
// Created by jnannie on 12/24/20.
//

#include "Form.hpp"

Form::Form() : _name("unnamed"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {

}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
	throw(GradeTooHighException, GradeTooLowException) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw GradeTooHighException();

	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const &other) :
		_name(other._name),
		_isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute),
		_target(other._target) {

}

Form &Form::operator=(Form const &other) {
	if (this == &other)
		return (*this);

	this->_isSigned = other._isSigned;
	this->_target = other._target;
	return (*this);
}

Form::~Form() {

}

std::string const &Form::getName() const {
	return (this->_name);
}

int Form::getGradeToSign() const{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat) throw(GradeTooHighException) {
	if (bureaucrat.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw GradeTooHighException();
}

bool Form::isSigned() const {
	return (this->_isSigned);
}

void Form::setTarget(std::string const &target) {
	this->_target = target;
}

std::string const &Form::getTarget() const {
	return (this->_target);
}


const char *Form::GradeTooHighException::what() const throw() {
	return ("form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("form grade is too low");
}

std::ostream &operator<<(std::ostream &stream, Form const &form) {
	stream << "form name: " << form.getName()
		<< ", grade needed to sign: " << form.getGradeToSign()
		<< ", grade needed to execute: " << form.getGradeToExecute()
		<< ", target: " << form.getTarget()
		<< ", state: " << form.isSigned();
	return (stream);
}