//
// Created by jnannie on 12/23/20.
//

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *_learned[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);
	virtual ~MateriaSource();

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(std::string const &type);
};


#endif //MATERIASOURCE_HPP
