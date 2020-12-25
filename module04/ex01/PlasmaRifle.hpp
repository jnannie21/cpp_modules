//
// Created by jnannie on 12/22/20.
//

#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {
public:
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const &other);
	PlasmaRifle &operator=(PlasmaRifle const &other);
	virtual ~PlasmaRifle();

	virtual void attack() const;

};


#endif //PLASMARIFLE_HPP
