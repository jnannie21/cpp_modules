#include "FragTrap.hpp"

int main() {
	FragTrap ft("firstFT");

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

	return 0;
}
