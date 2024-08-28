#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	ClapTrap wizard("Merlin the Wizard");
	ScavTrap gnome("David the Gnome");
	FragTrap goblin("Small Feet");

	wizard.printStats();
	std::cout << std::endl;
	gnome.printStats();
	std::cout << std::endl;
	goblin.printStats();
	std::cout << std::endl;

	wizard.attack("Goblin Frodo");
	wizard.takeDamage(2);
	wizard.beRepaired(1);
	std::cout << std::endl;
	gnome.attack("sister Minnie");
	gnome.guardGate();
	gnome.takeDamage(7);
	gnome.beRepaired(5);
	std::cout << std::endl;
	goblin.attack("Elf Flobbs");
	goblin.takeDamage(4);
	goblin.beRepaired(5);
	goblin.highFivesGuy();
	return (0);
}
