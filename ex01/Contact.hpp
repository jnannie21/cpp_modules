/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:52:56 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/09 16:24:21 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
// #include <iostream>

class	Contact {
public:
	Contact() {};
	~Contact() {};

	std::string		&getFirstName(void);
	std::string		&getLastName(void);
	std::string		&getNickname(void);
	std::string		&getLogin(void);
	std::string		&getPostalAddress(void);
	std::string		&getEmailAddress(void);
	std::string		&getPhoneNumber(void);
	std::string		&getBirthdayDate(void);
	std::string		&getFavoriteMeal(void);
	std::string		&getUnderwearColor(void);
	std::string		&getDarkestSecret(void);

	static int		getN(void);
	static void		increaseN(void);

private:
	std::string		firstName;
	std::string		lastName;
	std::string		nickname;
	std::string		login;
	std::string		postalAddress;
	std::string		emailAddress;
	std::string		phoneNumber;
	std::string		birthdayDate;
	std::string		favoriteMeal;
	std::string		underwearColor;
	std::string		darkestSecret;

	static int		_n;
};

#endif // PHONEBOOK_HPP
