/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:01:33 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/08 21:11:24 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int				Contact::getN(void) {
	return (Contact::_n);
}

void			Contact::increaseN(void) {
	Contact::_n++;
}

std::string		&Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string		&Contact::getLastName(void)
{
	return (this->lastName);
}

std::string		&Contact::getNickname(void)
{
	return (this->nickname);
}

std::string		&Contact::getLogin(void)
{
	return (this->login);
}

std::string		&Contact::getPostalAddress(void)
{
	return (this->postalAddress);
}

std::string		&Contact::getEmailAddress(void)
{
	return (this->emailAddress);
}

std::string		&Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

std::string		&Contact::getBirthdayDate(void)
{
	return (this->birthdayDate);
}

std::string		&Contact::getFavoriteMeal(void)
{
	return (this->favoriteMeal);
}

std::string		&Contact::getUnderwearColor(void)
{
	return (this->underwearColor);
}

std::string		&Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}

int		Contact::_n = 0;
