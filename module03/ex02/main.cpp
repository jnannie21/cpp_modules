#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	FragTrap ft("FT");
	ScavTrap st("ST");

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

	st.meleeAttack("enemy trooper");
	st.takeDamage(30);
	st.rangedAttack("enemy archer");
	st.takeDamage(4);

	st.beRepaired(50);

	st.challengeNewcomer();
	st.challengeNewcomer();
	st.challengeNewcomer();
	st.takeDamage(110);

	return 0;
}
