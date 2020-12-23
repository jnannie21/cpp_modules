//
// Created by jnannie on 12/23/20.
//

#include "MateriaSource.hpp"
#include <stddef.h>

MateriaSource::MateriaSource() : _learned() {

}

MateriaSource::MateriaSource(MateriaSource const &other) : _learned() {
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
	if (this == &other)
		return (*this);

	for (int i = 0; i < 4; i++)
		delete this->_learned[i];

	for (int i = 0; i < 4; i++)
	{
		if (other._learned[i])
			this->_learned[i] = other._learned[i]->clone();
		else
			this->_learned[i] = NULL;
	}

	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (this->_learned[i] == this->_learned[j])
				this->_learned[j] = NULL;
		}
		delete this->_learned[i];
	}

}

void MateriaSource::learnMateria(AMateria *materia) {
	if (!materia)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_learned[i])
		{
			this->_learned[i] = materia;
			break ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i] && this->_learned[i]->getType() == type)
			return (this->_learned[i]->clone());
	}
	return (NULL);
}
