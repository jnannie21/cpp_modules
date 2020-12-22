//
// Created by jnannie on 12/22/20.
//

#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "Victim.hpp"
#include <string>

class Sorcerer {
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const &other);
	Sorcerer &operator=(Sorcerer const &other);
	~Sorcerer(void);

	std::string getName(void) const;
	std::string getTitle(void) const;
	void polymorph(Victim const &victim) const;

private:
	Sorcerer(void);

	std::string _name;
	std::string _title;

};

std::ostream &operator<<(std::ostream &stream, Sorcerer const &sorcerer);

#endif //SORCERER_HPP
