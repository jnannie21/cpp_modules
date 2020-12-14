//
// Created by jnannie on 12/13/20.
//

#include "Pony.hpp"
#include <iostream>

const std::string Pony::_string_colors[] = {
		"white",
		"blue",
		"red",
};

Pony::Pony(void) : _name("unnamed_pony"), _color(COLOR_WHITE), _is_walking(false) {
	std::cout << "pony " << this->_name << " is created!" << std::endl;
}

Pony::~Pony(void) {
	std::cout << "pony " << this->_name << " is destructed!" << std::endl;
}

void Pony::walk(void) {
	this->_is_walking = true;
	std::cout << "pony " << this->_name << " is walking!" << std::endl;
}

void Pony::stop(void) {
	this->_is_walking = false;
	std::cout << "pony " << this->_name << " is stopped!" << std::endl;
}

void Pony::sayName(void) const {
	std::cout << "my name is " << this->_name << std::endl;
}

void Pony::sayColor(void) const {
	std::cout << "my color is " << this->_string_colors[this->_color] << std::endl;
}

void Pony::changeName(std::string &new_name) {
	std::cout << "pony " << this->_name << " changed name to " << new_name << std::endl;
	this->_name = new_name;
}

void Pony::changeColor(PonyColor new_color) {
	this->_color = new_color;
	std::cout << "pony " << this->_name << " changed color to " << this->_string_colors[this->_color] << std::endl;
}
