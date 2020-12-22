//
// Created by jnannie on 12/22/20.
//

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy {
public:
	RadScorpion();
	RadScorpion(RadScorpion const &other);
	RadScorpion &operator=(RadScorpion const &other);
	~RadScorpion();

};


#endif //RADSCORPION_HPP
