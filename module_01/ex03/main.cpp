#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main(void)
{
	{
		Weapon club = Weapon("baseball bat");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("knife");
		bob.attack();
	}
	{
		Weapon club = Weapon("machete");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("AK-47");
		jim.attack();
	}
	return 0;
}