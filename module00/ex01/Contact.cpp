//
// Created by Johnette Nannie on 12/12/20.
//

#include "Contact.hpp"
#include <iostream>
#include "Common.hpp"

Contact::Contact(void) : _isEmpty(1) {}

Contact::~Contact(void) {}

std::string		Contact::getField(int fieldNumber) const {
	return (this->_fields[fieldNumber]);
}

void			Contact::setField(int fieldNumber, std::string field) {
	this->_fields[fieldNumber] = field;
	if (this->_fields[fieldNumber].length())
		this->_isEmpty = 0;
}

int				Contact::isEmpty(void) const {
	return (this->_isEmpty);
}

void	Contact::enterContact(void) {
	std::cout << "enter first name: ";
	this->setField(Contact::FIRST_NAME, Common::getLineSafe());
	std::cout << "enter last name: ";
	this->setField(Contact::LAST_NAME, Common::getLineSafe());
	std::cout << "enter nickname: ";
	this->setField(Contact::NICKNAME, Common::getLineSafe());
	std::cout << "enter login: ";
	this->setField(Contact::LOGIN, Common::getLineSafe());
	std::cout << "enter postal address: ";
	this->setField(Contact::POSTAL_ADDRESS, Common::getLineSafe());
	std::cout << "enter email address: ";
	this->setField(Contact::EMAIL_ADDRESS, Common::getLineSafe());
	std::cout << "enter phone number: ";
	this->setField(Contact::PHONE_NUMBER, Common::getLineSafe());
	std::cout << "enter birthday date: ";
	this->setField(Contact::BIRTHDAY_DATE, Common::getLineSafe());
	std::cout << "enter favorite meal: ";
	this->setField(Contact::FAVORITE_MEAL, Common::getLineSafe());
	std::cout << "enter underwear color: ";
	this->setField(Contact::UNDERWEAR_COLOR, Common::getLineSafe());
	std::cout << "enter darkest secret: ";
	this->setField(Contact::DARKEST_SECRET, Common::getLineSafe());
}

void	Contact::printContact(void) const {
	std::cout <<  "first name: ";
	std::cout << this->_fields[Contact::FIRST_NAME] << std::endl;
	std::cout << "last name: ";
	std::cout << this->_fields[Contact::LAST_NAME] << std::endl;
	std::cout << "nickname: ";
	std::cout << this->_fields[Contact::NICKNAME] << std::endl;
	std::cout << "login: ";
	std::cout << this->_fields[Contact::LOGIN] << std::endl;
	std::cout << "postal address: ";
	std::cout << this->_fields[Contact::POSTAL_ADDRESS] << std::endl;
	std::cout << "email address: ";
	std::cout << this->_fields[Contact::EMAIL_ADDRESS] << std::endl;
	std::cout << "phone number: ";
	std::cout << this->_fields[Contact::PHONE_NUMBER] << std::endl;
	std::cout << "birthday date: ";
	std::cout << this->_fields[Contact::BIRTHDAY_DATE] << std::endl;
	std::cout << "favorite meal: ";
	std::cout << this->_fields[Contact::FAVORITE_MEAL] << std::endl;
	std::cout << "underwear color: ";
	std::cout << this->_fields[Contact::UNDERWEAR_COLOR] << std::endl;
	std::cout << "darkest secret: ";
	std::cout << this->_fields[Contact::DARKEST_SECRET] << std::endl;
}
