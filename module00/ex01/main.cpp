/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:12:49 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/11 22:40:23 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

#define MAX_NUMBER_OF_CONTACTS 8
#define COLUMN_WIDTH 10

std::string	get_line_safe(void)
{
	std::string		str;

	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << std::endl << "eof was reached. exiting." << std::endl;
		exit(1);
	}
	return (str);
}

void	enter_contact(Contact *contact) {
	std::cout << "enter first name: ";
	contact->setField(Contact::fieldFirstName, get_line_safe());
	std::cout << "enter last name: ";
	contact->setField(Contact::fieldLastName, get_line_safe());
	std::cout << "enter nickname: ";
	contact->setField(Contact::fieldNickname, get_line_safe());
	std::cout << "enter login: ";
	contact->setField(Contact::fieldLogin, get_line_safe());
	std::cout << "enter postal address: ";
	contact->setField(Contact::fieldPostalAddress, get_line_safe());
	std::cout << "enter email address: ";
	contact->setField(Contact::fieldEmailAddress, get_line_safe());
	std::cout << "enter phone number: ";
	contact->setField(Contact::fieldPhoneNumber, get_line_safe());
	std::cout << "enter birthday date: ";
	contact->setField(Contact::fieldBirthdayDate, get_line_safe());
	std::cout << "enter favorite meal: ";
	contact->setField(Contact::fieldFavoriteMeal, get_line_safe());
	std::cout << "enter underwear color: ";
	contact->setField(Contact::fieldUnderwearColor, get_line_safe());
	std::cout << "enter darkest secret: ";
	contact->setField(Contact::fieldDarkestSecret, get_line_safe());
}

void	print_contact(Contact *contact) {
	std::cout <<  "first name: ";
	std::cout << contact->getField(Contact::fieldFirstName) << std::endl;
	std::cout << "last name: ";
	std::cout << contact->getField(Contact::fieldLastName) << std::endl;
	std::cout << "nickname: ";
	std::cout << contact->getField(Contact::fieldNickname) << std::endl;
	std::cout << "login: ";
	std::cout << contact->getField(Contact::fieldLogin) << std::endl;
	std::cout << "postal address: ";
	std::cout << contact->getField(Contact::fieldPostalAddress) << std::endl;
	std::cout << "email address: ";
	std::cout << contact->getField(Contact::fieldEmailAddress) << std::endl;
	std::cout << "phone number: ";
	std::cout << contact->getField(Contact::fieldPhoneNumber) << std::endl;
	std::cout << "birthday date: ";
	std::cout << contact->getField(Contact::fieldBirthdayDate) << std::endl;
	std::cout << "favorite meal: ";
	std::cout << contact->getField(Contact::fieldFavoriteMeal) << std::endl;
	std::cout << "underwear color: ";
	std::cout << contact->getField(Contact::fieldUnderwearColor) << std::endl;
	std::cout << "darkest secret: ";
	std::cout << contact->getField(Contact::fieldDarkestSecret) << std::endl;
}

std::string		format_entry(std::string entry)
{
	std::string		formatted_entry;

	formatted_entry = entry;
	if (formatted_entry.length() > COLUMN_WIDTH)
	{
		formatted_entry.resize(COLUMN_WIDTH);
		formatted_entry[COLUMN_WIDTH - 1] = '.';
	}
	return (formatted_entry);
}

void	print_preview_of_contacts(Contact *contact) {
	int				i = 0;

	while (i < Contact::getN())
	{
		if (!(contact[i].isEmpty()))
		{
			std::cout << std::setw(COLUMN_WIDTH) << i << "|";
			std::cout << std::setw(COLUMN_WIDTH) << format_entry(contact[i].getField(Contact::fieldFirstName)) << "|";
			std::cout << std::setw(COLUMN_WIDTH) << format_entry(contact[i].getField(Contact::fieldLastName)) << "|";
			std::cout << std::setw(COLUMN_WIDTH) << format_entry(contact[i].getField(Contact::fieldNickname));
			std::cout << std::endl;
		}
		i++;
	}
}

void	add_contact(Contact *contacts)
{
	if (Contact::getN() < 8)
	{
		enter_contact(&contacts[Contact::getN()]);
		Contact::increaseN();
	}
	else
		std::cout << "you can't add more than 8 contacts" << std::endl;
}

int		get_index(std::string str)
{
	if (str.length() == 0 || str.length() > 1 || str[0] < 48 || str[0] > 57)
		return (-1);
	return (str[0] - 48);
}

void	search_contact(Contact *contacts)
{
	int		index;

	if (Contact::getN() > 0)
	{
		std::cout << "available contacts:" << std::endl;
		std::cout << std::setw(10) << "index" << "|";
		std::cout << std::setw(10) << "first name" << "|";
		std::cout << std::setw(10) << "last name" << "|";
		std::cout << std::setw(10) << "nickname" << std::endl;
		print_preview_of_contacts(contacts);
		while (1)
		{
			std::cout << "enter index of the available entry[0, " << Contact::getN() - 1 << "]: ";
			index = get_index(get_line_safe());
			if (index < 0 || index >= Contact::getN())
				std::cout << "wrong index(must be in interval [0, " << Contact::getN() - 1 << "])" << std::endl;
			else
			{
				if (contacts[index].isEmpty())
					std::cout << "contact[" << index << "]" << "is empty." << std::endl;
				else
					print_contact(&contacts[index]);
				break ;
			}
		}
	}
	else
		std::cout << "there is no entries yet, type ADD to add contact" << std::endl;
}

int		main(void) {
	Contact			contacts[MAX_NUMBER_OF_CONTACTS];
	std::string		command;

	while (1)
	{
		std::cout << "Please, enter command and press enter: ";
		command = get_line_safe();
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			add_contact(contacts);
		else if (command == "SEARCH")
			search_contact(contacts);
		else
			std::cout << "there is no command \"" << command << "\"" << std::endl;
	}
	return (0);
}
