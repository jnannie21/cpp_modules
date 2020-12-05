/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:12:49 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/05 21:51:38 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

#define MAX_NUMBER_OF_CONTACTS 8
#define COLUMN_WIDTH 10

void	enter_contact(Contact *contact) {
	std::cout << "enter first name: ";
	std::getline(std::cin, contact->first_name);
	std::cout << "enter last name: ";
	std::getline(std::cin, contact->last_name);
	std::cout << "enter nickname: ";
	std::getline(std::cin, contact->nickname);
	std::cout << "enter login: ";
	std::getline(std::cin, contact->login);
	std::cout << "enter postal address: ";
	std::getline(std::cin, contact->postal_address);
	std::cout << "enter email address: ";
	std::getline(std::cin, contact->email_address);
	std::cout << "enter phone number: ";
	std::getline(std::cin, contact->phone_number);
	std::cout << "enter birthday date: ";
	std::getline(std::cin, contact->birthday_date);
	std::cout << "enter favorite meal: ";
	std::getline(std::cin, contact->favorite_meal);
	std::cout << "enter underwear color: ";
	std::getline(std::cin, contact->underwear_color);
	std::cout << "enter darkest secret: ";
	std::getline(std::cin, contact->darkest_secret);
}

void	print_contact(Contact *contact) {
	std::cout <<  "first name: ";
	std::cout << contact->first_name << std::endl;
	std::cout << "last name: ";
	std::cout << contact->last_name << std::endl;
	std::cout << "nickname: ";
	std::cout << contact->nickname << std::endl;
	std::cout << "login: ";
	std::cout << contact->login << std::endl;
	std::cout << "postal address: ";
	std::cout << contact->postal_address << std::endl;
	std::cout << "email address: ";
	std::cout << contact->email_address << std::endl;
	std::cout << "phone number: ";
	std::cout << contact->phone_number << std::endl;
	std::cout << "birthday date: ";
	std::cout << contact->birthday_date << std::endl;
	std::cout << "favorite meal: ";
	std::cout << contact->favorite_meal << std::endl;
	std::cout << "underwear color: ";
	std::cout << contact->underwear_color << std::endl;
	std::cout << "darkest secret: ";
	std::cout << contact->darkest_secret << std::endl;
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

void	print_preview_contacts(Contact *contact) {
	int				i = 0;

	while (i < Contact::getN())
	{
		std::cout << std::setw(COLUMN_WIDTH + 1) << i << "|";
		std::cout << std::setw(COLUMN_WIDTH + 1) << format_entry(contact[i].first_name) << "|";
		std::cout << std::setw(COLUMN_WIDTH + 1) << format_entry(contact[i].last_name) << "|";
		std::cout << std::setw(COLUMN_WIDTH + 1) << format_entry(contact[i].nickname) << "|";
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
		print_preview_contacts(contacts);
		while (1)
		{
			std::cout << "enter index of the available entry[0, " << Contact::getN() - 1 << "]: ";
			std::cin >> index;
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
	// int				index;

	while (1)
	{
		std::cout << "Please, enter command: ";
		std::cin >> command;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
