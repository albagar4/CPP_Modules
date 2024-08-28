#include "ClapTrap.hpp"

int main(void){
	ClapTrap wizard("Merlin the Wizard");
	ClapTrap gnome("David the Gnome");

	wizard.attack("Goblin Frodo");
	wizard.takeDamage(2);
	wizard.beRepaired(1);
	gnome.takeDamage(15);
	gnome.beRepaired(5);
	return (0);
}
