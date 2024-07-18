#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	std::cout << "Calling phonebook constructor" << std::endl;
	return;
}

PhoneBook::~PhoneBook(){
	std::cout << "Calling phonebook destructor" << std::endl;
	return;
}

void	PhoneBook::printContacts(){
	for (int i = 0; i < 8; i++)
	{
		// std::cout << "Contact no. " << i + 1 << std::endl;
		for (int j = 0; j < 5; j++)
		{
			std::cout << this->contacts[i].getTitle(j);
			std::cout << this->contacts[i].getInfo(j) << std::endl;
		}
	}
}

void	PhoneBook::addContact(std::string contactInfo[5]){
	if (!this->contacts[7].empty())
	{
		this->shiftContact();
		this->contacts[0].setInfo(contactInfo);
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (this->contacts[i].empty())
			{
				this->contacts[i].setInfo(contactInfo);
				return;
			}
		}
	}
}

void	PhoneBook::shiftContact(){
	for (int i = 0; i < 7; i++)
		this->contacts[i] = this->contacts[i + 1];
}

std::string	PhoneBook::menuSelector(){
	std::string	input;

	std::cout << "Menu of your PhoneBook, please select an option:" << std::endl;
	std::cout << "- ADD" << std::endl << "- SEARCH" << std::endl << "- EXIT" << std::endl;
	std::getline (std::cin, input);
	if (input == "ADD")
		;
	if (input == "SEARCH")
		;
	if (input == "EXIT")
		;
	else
		std::cout << "Eres tonto??" << std::endl;
	return (input);
}
