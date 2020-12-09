/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:12:49 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/08 21:49:05 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

#define MAX_NUMBER_OF_CONTACTS 8
#define COLUMN_WIDTH 10

void	check_input_for_errors(void)
{
	if (std::cin.fail() || std::cin.eof())
	{
		std::cerr << std::endl << "input error" << std::endl;
		exit(1);
	}
}

void	get_line_safe(std::string &str)
{
	std::getline(std::cin, str);
	check_input_for_errors();
}

void	enter_contact(Contact *contact) {
	std::cout << "enter first name: ";
	get_line_safe(contact->getFirstName());
	std::cout << "enter last name: ";
	get_line_safe(contact->getLastName());
	std::cout << "enter nickname: ";
	get_line_safe(contact->getNickname());
	std::cout << "enter login: ";
	get_line_safe(contact->getLogin());
	std::cout << "enter postal address: ";
	get_line_safe(contact->getPostalAddress());
	std::cout << "enter email address: ";
	get_line_safe(contact->getEmailAddress());
	std::cout << "enter phone number: ";
	get_line_safe(contact->getPhoneNumber());
	std::cout << "enter birthday date: ";
	get_line_safe(contact->getBirthdayDate());
	std::cout << "enter favorite meal: ";
	get_line_safe(contact->getFavoriteMeal());
	std::cout << "enter underwear color: ";
	get_line_safe(contact->getUnderwearColor());
	std::cout << "enter darkest secret: ";
	get_line_safe(contact->getDarkestSecret());
}

void	print_contact(Contact *contact) {
	std::cout <<  "first name: ";
	std::cout << contact->getFirstName() << std::endl;
	std::cout << "last name: ";
	std::cout << contact->getLastName() << std::endl;
	std::cout << "nickname: ";
	std::cout << contact->getNickname() << std::endl;
	std::cout << "login: ";
	std::cout << contact->getLogin() << std::endl;
	std::cout << "postal address: ";
	std::cout << contact->getPostalAddress() << std::endl;
	std::cout << "email address: ";
	std::cout << contact->getEmailAddress() << std::endl;
	std::cout << "phone number: ";
	std::cout << contact->getPhoneNumber() << std::endl;
	std::cout << "birthday date: ";
	std::cout << contact->getBirthdayDate() << std::endl;
	std::cout << "favorite meal: ";
	std::cout << contact->getFavoriteMeal() << std::endl;
	std::cout << "underwear color: ";
	std::cout << contact->getUnderwearColor() << std::endl;
	std::cout << "darkest secret: ";
	std::cout << contact->getDarkestSecret() << std::endl;
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
		std::cout << std::setw(COLUMN_WIDTH) << i << "|";
		std::cout << std::setw(COLUMN_WIDTH) << format_entry(contact[i].getFirstName()) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << format_entry(contact[i].getLastName()) << "|";
		std::cout << std::setw(COLUMN_WIDTH) << format_entry(contact[i].getNickname());
		std::cout << std::endl;
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

void	search_contact(Contact *contacts)
{
	int		index;

	std::cout << "available contacts:" << std::endl;
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;
	if (Contact::getN() > 0)
	{
		print_preview_of_contacts(contacts);
		while (1)
		{
			std::cout << "enter index of the available entry[0, " << Contact::getN() - 1 << "]: ";
			std::cin >> index;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			check_input_for_errors();
			if (index < 0 || index >= Contact::getN())
				std::cout << "wrong index(must be in interval [0, " << Contact::getN() - 1 << "])" << std::endl;
			else
			{
				print_contact(contacts + index);
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
		get_line_safe(command);
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
