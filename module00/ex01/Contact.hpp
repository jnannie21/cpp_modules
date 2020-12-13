//
// Created by Johnette Nannie on 12/12/20.
//

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class	Contact {
public:
						Contact(void);
						~Contact(void);

	enum {
						FIRST_NAME,
						LAST_NAME,
						NICKNAME,
						LOGIN,
						POSTAL_ADDRESS,
						EMAIL_ADDRESS,
						PHONE_NUMBER,
						BIRTHDAY_DATE,
						FAVORITE_MEAL,
						UNDERWEAR_COLOR,
						DARKEST_SECRET,
//						NUMBER_OF_FIELDS
	};

	std::string			getField(int fieldNumber) const;
	void				setField(int fieldNumber, std::string field);
	int					isEmpty(void) const;
	void				enterContact(void);
	void				printContact(void) const;

private:
	std::string			_fields[11];
	int					_isEmpty;
};

#endif //CONTACT_HPP
