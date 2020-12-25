//
// Created by jnannie on 12/25/20.
//

#ifndef MACHINEGUN_HPP
#define MACHINEGUN_HPP


#include "AWeapon.hpp"

class MachineGun : public AWeapon {
public:
	MachineGun();
	MachineGun(MachineGun const &other);
	MachineGun &operator=(MachineGun const &other);
	virtual ~MachineGun();

	virtual void attack() const;

};


#endif //MACHINEGUN_HPP
