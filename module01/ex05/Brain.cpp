//
// Created by jnannie on 12/15/20.
//

#include "Brain.hpp"
#include <iostream>
#include <sstream>

std::string Brain::identify(void) const {
	std::ostringstream strstream;

	strstream << "0x" << std::hex << std::uppercase << (unsigned long)this;
	return (strstream.str());
}
