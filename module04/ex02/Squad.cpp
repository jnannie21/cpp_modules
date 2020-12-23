//
// Created by jnannie on 12/23/20.
//

#include "Squad.hpp"
#include <stddef.h>

Squad::Squad() : _count(0), _units(NULL) {

}

Squad::Squad(Squad const &other) : _count(0), _units(NULL) {
	*this = other;
}

Squad &Squad::operator=(Squad const &other) {
	if (this == &other)
		return (*this);

	for (int i = 0; i < this->_count; i++)
		delete this->_units[i];
	delete [] this->_units;

	this->_count = other._count;
	if (this->_count > 0)
	{
		this->_units = new ISpaceMarine *[this->_count];
		for (int i = 0; i < this->_count; i++)
			this->_units[i] = other._units[i]->clone();
	}
	else
		this->_units = NULL;
	return (*this);
}

Squad::~Squad() {
	if (!this->_units)
		return ;

	for (int i = 0; i < this->_count; i++)
		delete this->_units[i];
	delete [] this->_units;
}

int Squad::getCount() const {
	return (this->_count);
}

ISpaceMarine *Squad::getUnit(int i) const {
	return (this->_units[i]);
}

int Squad::push(ISpaceMarine *unit) {
	if (!unit)
		return (this->_count);

	for (int i = 0; i < this->_count; i++)
	{
		if (this->_units[i] == unit)
			return (this->_count);
	}

	ISpaceMarine **units = new ISpaceMarine *[this->_count + 1];

	for (int i = 0; i < this->_count; i++)
		units[i] = this->_units[i];

	units[this->_count] = unit;
	this->_count++;
	delete [] this->_units;
	this->_units = units;
	return (this->_count);
}
