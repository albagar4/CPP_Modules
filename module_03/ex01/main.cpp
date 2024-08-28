#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void){
	ClapTrap wizard("Merlin the Wizard");
	ScavTrap gnome("David the Gnome");

	wizard.printStats();
	std::cout << std::endl;
	gnome.printStats();
	std::cout << std::endl;
	wizard.attack("Goblin Frodo");
	wizard.takeDamage(2);
	wizard.beRepaired(1);
	std::cout << std::endl;
	gnome.attack("sister Minnie");
	gnome.guardGate();
	gnome.takeDamage(7);
	gnome.beRepaired(5);
	return (0);
}
