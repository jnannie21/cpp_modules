#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>

int main() {
	FragTrap ft("FT");

	ft.meleeAttack("enemy trooper");
	ft.takeDamage(30);
	ft.rangedAttack("enemy archer");
	ft.takeDamage(4);

	ft.beRepaired(50);

	ft.vaultHunterDotExe("enemy panzer");
	ft.vaultHunterDotExe("enemy panzer");
	ft.vaultHunterDotExe("enemy panzer");
	ft.vaultHunterDotExe("enemy panzer");
	ft.vaultHunterDotExe("enemy panzer");
	ft.takeDamage(110);

	std::cout << "---------------------" << std::endl;

	ScavTrap st("ST");

	st.meleeAttack("enemy trooper");
	st.takeDamage(30);
	st.rangedAttack("enemy archer");
	st.takeDamage(4);

	st.beRepaired(50);

	st.challengeNewcomer();
	st.challengeNewcomer();
	st.challengeNewcomer();
	st.takeDamage(110);

	std::cout << "---------------------" << std::endl;

	NinjaTrap nt("NT");

	nt.meleeAttack("enemy trooper");
	nt.takeDamage(30);
	nt.rangedAttack("enemy archer");
	nt.takeDamage(4);

	nt.beRepaired(50);

	nt.ninjaShoebox(ft);
	nt.ninjaShoebox(st);
	nt.ninjaShoebox(nt);
	ClapTrap ct;
	nt.ninjaShoebox(ct);
	nt.takeDamage(110);

	std::cout << "---------------------" << std::endl;

	SuperTrap superTp("superTp");

	superTp.meleeAttack("enemy trooper");
	superTp.takeDamage(30);
	superTp.rangedAttack("enemy archer");
	superTp.takeDamage(4);

	superTp.beRepaired(50);

	superTp.vaultHunterDotExe("enemy panzer");
	superTp.vaultHunterDotExe("enemy panzer");
	superTp.vaultHunterDotExe("enemy panzer");
	superTp.vaultHunterDotExe("enemy panzer");
	superTp.vaultHunterDotExe("enemy panzer");

	superTp.ninjaShoebox(ft);
	superTp.ninjaShoebox(st);
	superTp.ninjaShoebox(nt);
	superTp.takeDamage(110);

	return 0;
}
