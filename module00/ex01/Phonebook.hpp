//
// Created by Johnette Nannie on 12/12/20.
//

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"

class Phonebook {
public:
						Phonebook(void);
						~Phonebook(void);

	void				addContact(void);
	void				printPreviewOfContacts(void) const;
	void				searchContact(void) const;
	void 				execute(void);

	static int			getN(void);

	static int const	COLUMN_WIDTH = 10;
	static int const	MAX_NUMBER_OF_CONTACTS = 8;

private:
	void				increaseN(void);
	int					getIndex(void) const;
	std::string			formatField(std::string field) const;

	Contact				_contacts[MAX_NUMBER_OF_CONTACTS];
	static int			_n;
};

#endif //PHONEBOOK_HPP
