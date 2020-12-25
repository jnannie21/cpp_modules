//
// Created by jnannie on 12/22/20.
//

#ifndef VICTIM_HPP
#define VICTIM_HPP

#include <string>

class Victim {
public:
	Victim(void);
	Victim(std::string name);
	Victim(Victim const &other);
	Victim &operator=(Victim const &other);
	virtual ~Victim(void);

	std::string getName(void) const;
	virtual void getPolymorphed(void) const;

protected:
	std::string _name;

};

std::ostream &operator<<(std::ostream &stream, Victim const &victim);

#endif //VICTIM_HPP
