//
// Created by jnannie on 12/25/20.
//

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) :
	Form(other) {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	if (this == &other)
		return (*this);

	Form::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	throw(GradeTooHighException, GradeTooLowException) :
	Form("ShrubberyCreationForm", 145, 137) {
	this->setTarget(target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
	throw(NotSignedException, GradeTooHighException) {
	if (!this->isSigned())
		throw NotSignedException();

	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooHighException();

	std::ofstream outfile((this->getTarget() + "_shrubbery").c_str());

	outfile << "root" << std::endl;
	outfile << "+-- dir1" << std::endl;
	outfile << "    +-- file1" << std::endl;
	outfile << "+-- dir3" << std::endl;
	outfile << "    +-- file2" << std::endl;
	outfile << "    +-- file3" << std::endl;
	outfile << "    +-- dir4" << std::endl;
	outfile << "        +-- file4" << std::endl;
	outfile << "+-- file5" << std::endl;

	outfile.close();
}

const char *ShrubberyCreationForm::NotSignedException::what() const throw() {
	return ("ShrubberyCreationForm not signed");
}
