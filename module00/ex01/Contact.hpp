/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:52:56 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/11 21:35:54 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>

class	Contact {
public:
	Contact();
	~Contact();

	enum {
					fieldFirstName,
					fieldLastName,
					fieldNickname,
					fieldLogin,
					fieldPostalAddress,
					fieldEmailAddress,
					fieldPhoneNumber,
					fieldBirthdayDate,
					fieldFavoriteMeal,
					fieldUnderwearColor,
					fieldDarkestSecret
	};

	std::string		getField(int fieldNumber) const;
	void			setField(int fieldNumber, std::string field);
	static int		getN(void);
	static void		increaseN(void);
	int				isEmpty();

private:
	std::string		_fields[11];
	int				_isEmpty;

	static int		_n;
};

#endif
