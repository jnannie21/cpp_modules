//
// Created by jnannie on 12/22/20.
//

#ifndef POWERFIST_HPP
#define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
public:
	PowerFist();
	PowerFist(PowerFist const &other);
	PowerFist &operator=(PowerFist const &other);
	virtual ~PowerFist();

	virtual void attack() const;

};


#endif //POWERFIST_HPP
