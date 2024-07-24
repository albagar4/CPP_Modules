#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	std::cout << "Calling phonebook constructor" << std::endl;
	return;
}

PhoneBook::~PhoneBook(){
	std::cout << "Calling phonebook destructor" << std::endl;
	return;
}

bool	PhoneBook::isAllDigit(std::string data){
	for (int i = 0; i < (int)data.length(); i++)
	{
		if (!std::isdigit(data[i]))
			return (false);
	}
	return (true);
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

void	PhoneBook::displayAgenda(){
	std::cout << " ------------------------------------------- ";
	std::cout << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	return;
}

void	PhoneBook::displayContact(std::string input){
	std::cout << "prout" << input << std::endl;
	return;
}

void	PhoneBook::searchContact(){
	std::string	input;

	this->displayAgenda();
	std::cout << "Select a number: " << std::endl;
	std::getline (std::cin, input);
	if ((input[0] >= '1' && input[0] <= '8') && input.length() == 1)
		this->displayContact(input);
	else
	{
		std::cout << "The index you introduced is not correct" << std::endl;
		this->searchContact();
	}
	return;
}

std::string	PhoneBook::menuSelector(){
	std::string	input;

	std::cout << "Menu of your PhoneBook, please select an option:" << std::endl;
	std::cout << "- ADD" << std::endl << "- SEARCH" << std::endl << "- EXIT" << std::endl;
	std::getline (std::cin, input);
	if (input == "ADD")
		this->fillFields();
	else if (input == "SEARCH")
		this->searchContact();
	else if (input == "EXIT")
		;
	else
		std::cout << "You must introduce a valid command" << std::endl;
	return (input);
}

void	PhoneBook::fillFields(){
	std::string	data[5];

	for (int i = 0; i < 5; i++)
	{
		std::cout << this->contacts[0].getTitle(i);
		std::getline(std::cin, data[i]);
		if (data[i].empty())
		{
			std::cout << "You can't have an empty field!" << std::endl;
			i--;
		}
		else if (i == 3 && (!this->isAllDigit(data[i])))
		{
			std::cout << "The phone number must be numeric!" << std::endl;
			i--;
		}
	}
	this->addContact(data);
	return ;
}
