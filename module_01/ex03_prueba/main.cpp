#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("baseball bat");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("knife");
		bob.attack();
	}
	{
		Weapon club = Weapon("baseball bat");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("glock 18");
		jim.attack();
	}
	return 0;
}