#include "PhoneBook.hpp"

// int main(void){
// 	PhoneBook	phonebook;
// 	std::string		test[] = {"Caca", "Prout", "Bite", "Cul", "Chatte"};

// 		phonebook.addContact(test);
// 		phonebook.printContacts();
// 	}
// 	return (0);
// }

int main ()
{
	PhoneBook	phonebook;
	std::string	key;

	while (key != "EXIT")
		key = phonebook.menuSelector();
	return 0;
}
