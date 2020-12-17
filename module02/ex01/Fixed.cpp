//
// Created by jnannie on 12/16/20.
//

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f) {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed &Fixed::operator=(const Fixed &f) {
	std::cout << "Assignation operator called" << std::endl;
	this->_raw = f.getRawBits();
	return (*this);
}

Fixed::Fixed(int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_raw = i << Fixed::_number_of_fractional_bits;
}

Fixed::Fixed(float f) {
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(f * (1 << Fixed::_number_of_fractional_bits));
}

int Fixed::getRawBits(void) const {
	return (this->_raw);
}

void Fixed::setRawBits(const int raw) {
	this->_raw = raw;
}

float Fixed::toFloat(void) const {
	return ((float)(this->_raw) / (1 << Fixed::_number_of_fractional_bits));
}

int Fixed::toInt(void) const {
	return (this->_raw >> Fixed::_number_of_fractional_bits);
}

std::ostream &operator<<(std::ostream &s, const Fixed &f) {
	s << f.toFloat();
	return (s);
}
