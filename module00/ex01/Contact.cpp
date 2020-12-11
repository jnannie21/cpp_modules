/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:01:33 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/11 18:43:36 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _isEmpty(1) {

}

Contact::~Contact() {

}

int				Contact::getN(void) {
	return (Contact::_n);
}

void			Contact::increaseN(void) {
	Contact::_n++;
}

std::string		Contact::getField(int fieldNumber) const {
	return (this->_fields[fieldNumber]);
}

void			Contact::setField(int fieldNumber, std::string field) {
	this->_fields[fieldNumber] = field;
	if (this->_fields[fieldNumber].length())
		this->_isEmpty = 0;
}

int				Contact::isEmpty() {
	return (this->_isEmpty);
}

int		Contact::_n = 0;
