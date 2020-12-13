//
// Created by Johnette Nannie on 12/12/20.
//

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include "Common.hpp"

int			Phonebook::_n = 0;

Phonebook::Phonebook(void) {}

Phonebook::~Phonebook(void) {}

int			Phonebook::getN(void) {
	return (Phonebook::_n);
}

void		Phonebook::increaseN(void) {
	Phonebook::_n++;
}

void		Phonebook::addContact(void) {
	if (Phonebook::getN() < 8)
	{
		this->_contacts[Phonebook::getN()].enterContact();
		this->increaseN();
	}
	else
		std::cout << "you can't add more than 8 contacts" << std::endl;
}

std::string	Phonebook::formatField(std::string field) const {
	if (field.length() > Phonebook::COLUMN_WIDTH)
	{
		field.resize(Phonebook::COLUMN_WIDTH);
		field[Phonebook::COLUMN_WIDTH - 1] = '.';
	}
	return (field);
}

void		Phonebook::printPreviewOfContacts(void) const {
	int			i = 0;

	while (i < Phonebook::getN())
	{
		if (!(this->_contacts[i].isEmpty()))
		{
			std::cout << std::setw(Phonebook::COLUMN_WIDTH) << i << "|";
			std::cout << std::setw(Phonebook::COLUMN_WIDTH) << formatField(this->_contacts[i].getField(Contact::FIRST_NAME)) << "|";
			std::cout << std::setw(Phonebook::COLUMN_WIDTH) << formatField(this->_contacts[i].getField(Contact::LAST_NAME)) << "|";
			std::cout << std::setw(Phonebook::COLUMN_WIDTH) << formatField(this->_contacts[i].getField(Contact::NICKNAME));
			std::cout << std::endl;
		}
		i++;
	}
}

int			Phonebook::getIndex(void) const {
	std::string	str = Common::getLineSafe();

	if (str.length() == 0 || str.length() > 1 || str[0] < 48 || str[0] > 57)
		return (-1);
	return (str[0] - 48);
}

void		Phonebook::searchContact(void) const {
	int		index;

	if (Phonebook::getN() > 0)
	{
		std::cout << "available contacts:" << std::endl;
		std::cout << std::setw(10) << "index" << "|";
		std::cout << std::setw(10) << "first name" << "|";
		std::cout << std::setw(10) << "last name" << "|";
		std::cout << std::setw(10) << "nickname" << std::endl;
		this->printPreviewOfContacts();
		while (1)
		{
			std::cout << "enter index of the available entry[0, " << Phonebook::getN() - 1 << "]: ";
			index = this->getIndex();
			if (index < 0)
				std::cout << "invalid index(must be positive number)." << std::endl;
			else if (index >= Phonebook::getN())
				std::cout << "wrong index(must be in interval [0, " << Phonebook::getN() - 1 << "])." << std::endl;
			else
			{
				if (this->_contacts[index].isEmpty())
					std::cout << "contact[" << index << "]" << " is empty." << std::endl;
				else
					this->_contacts[index].printContact();
				break ;
			}
		}
	}
	else
		std::cout << "there is no entries yet, type ADD to add contact" << std::endl;
}

void 		Phonebook::execute(void) {
	std::string		command;

	while (1)
	{
		std::cout << "Please, enter command and press enter: ";
		command = Common::getLineSafe();
		if (command == "EXIT" || std::cin.eof())
		{
			std::cout << "exit." << std::endl;
			break ;
		}
		else if (command == "ADD")
			this->addContact();
		else if (command == "SEARCH")
			this->searchContact();
		else
			std::cout << "there is no command \"" << command << "\"" << std::endl;
	}
}
