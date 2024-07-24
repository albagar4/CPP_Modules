#include "PhoneBook.hpp"

int main ()
{
	PhoneBook	phonebook;
	std::string	key;

	while (key != "EXIT")
		key = phonebook.menuSelector();
	return 0;
}
