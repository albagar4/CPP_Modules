#include "PhoneBook.hpp"

int main ()
{
	PhoneBook	phonebook;
	std::string	input;
	
	while (input != "EXIT")
	{
		phonebook.menuSelector();
		std::cout << GREEN;
		if (!std::getline (std::cin, input, '\n') || input == "EXIT")
			break ;
		std::cout << RESET;
		if (input == "ADD")
			phonebook.fillFields();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << RED << "You must introduce a valid command" << RNL;
	}
	return 0;
}
