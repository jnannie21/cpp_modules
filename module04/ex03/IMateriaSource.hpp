//
// Created by jnannie on 12/23/20.
//

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
public:
	virtual ~IMateriaSource() {};
	virtual void learnMateria(AMateria *materia) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif //IMATERIASOURCE_HPP
