//
// Created by jnannie on 12/15/20.
//

#ifndef HUMAN_HPP
#define HUMAN_HPP

#include "Brain.hpp"
#include <string>

class Human {
public:
	std::string identify(void) const;
	const Brain &getBrain(void) const;

private:
	const Brain _brain;

};


#endif //HUMAN_HPP
