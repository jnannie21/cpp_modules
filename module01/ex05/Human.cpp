//
// Created by jnannie on 12/15/20.
//

#include "Human.hpp"

std::string Human::identify(void) const {
	return (this->_brain.identify());
}
const Brain &Human::getBrain(void) const {
	return (this->_brain);
}
