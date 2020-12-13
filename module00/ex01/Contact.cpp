//
// Created by Johnette Nannie on 12/12/20.
//

#include "Contact.hpp"
#include <iostream>

std::string const	Contact::FIELDS_NAMES[] = {
		"first name",
		"last name",
		"nickname",
		"login",
		"postal address",
		"email address",
		"phone number",
		"birthday date",
		"favorite meal",
		"underwear color",
		"darkest secret",
};

Contact::Contact(void) : _isEmpty(1) {

}

Contact::~Contact(void) {

}

std::string		Contact::getField(int fieldNumber) const {
	return (this->_fields[fieldNumber]);
}

void	Contact::setField(int fieldNumber, std::string field) {
	this->_fields[fieldNumber] = field;
	if (this->_fields[fieldNumber].length())
		this->_isEmpty = 0;
}

int		Contact::isEmpty(void) const {
	return (this->_isEmpty);
}

void	Contact::enterContact(void) {
	int 	i = 0;

	while (i < Contact::NUMBER_OF_FIELDS)
	{
		std::cout << "enter " << Contact::FIELDS_NAMES[i] << ": ";
		std::getline(std::cin, this->_fields[i]);
		if (std::cin.eof())
			break ;
		if (!this->_fields[i].empty()
			&& this->_fields[i].find_first_not_of(" \t") != std::string::npos)
			this->_isEmpty = 0;
		i++;
	}
}

void	Contact::printContact(void) const {
	int 	i = 0;

	while (i < Contact::NUMBER_OF_FIELDS)
	{
		std::cout << Contact::FIELDS_NAMES[i] << ": ";
		std::cout << this->_fields[i] << std::endl;
		i++;
	}
}
