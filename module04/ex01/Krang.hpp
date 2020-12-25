//
// Created by jnannie on 12/25/20.
//

#ifndef KRANG_HPP
#define KRANG_HPP

#include "Enemy.hpp"

class Krang : public Enemy {
public:
	Krang();
	Krang(Krang const &other);
	Krang &operator=(Krang const &other);
	virtual ~Krang();

};


#endif //KRANG_HPP
