/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:01:33 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/05 19:43:19 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int		Contact::getN(void) {
	return (Contact::_n);
}

void	Contact::increaseN(void) {
	Contact::_n++;
}

int		Contact::_n = 0;