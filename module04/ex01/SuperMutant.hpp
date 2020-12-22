//
// Created by jnannie on 12/22/20.
//

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy {
public:
	SuperMutant();
	SuperMutant(SuperMutant const &other);
	SuperMutant &operator=(SuperMutant const &other);
	~SuperMutant();

	virtual void takeDamage(int damage);

};


#endif //SUPERMUTANT_HPP
