#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	// std::cout << "Calling phonebook constructor" << std::endl;
	return;
}

PhoneBook::~PhoneBook(){
	// std::cout << "Calling phonebook destructor" << std::endl;
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

void	PhoneBook::addContact(std::string contactInfo[5]){
	if (!this->contacts[7].empty())
	{
		this->shiftContact();
		this->contacts[7].setInfo(contactInfo);
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (this->contacts[i].empty())
			{
				this->contacts[i].setInfo(contactInfo);
				this->menuSelector();
				return;
			}
		}
	}
	this->menuSelector();
}

void	PhoneBook::shiftContact(){
	std::string	cpy_data[5];

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cpy_data[j] = this->contacts[i + 1].getInfo(j);
			this->contacts[i].setInfo(cpy_data);
		}
	}
}

void	PhoneBook::displayAgenda(){
	std::cout << CYAN << " ------------------------------------------- ";
	std::cout << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i + 1;
		for (int j = 0; j < 3; j++)
		{
			std::cout << "|";
			if (this->contacts[i].getInfo(j).length() < 10)
				std::cout << std::right << std::setw(10) << this->contacts[i].getInfo(j);
			else
				std::cout << this->contacts[i].getInfo(j).substr(0, 9) << ".";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ------------------------------------------- " << RNL;
	return;
}

void	PhoneBook::displayContact(std::string input){
	int	i;

	i = atoi(input.c_str()) - 1;
	if (!this->contacts[i].getInfo(0).empty())
	{
		for (int j = 0; j < 5; j++)
			std::cout << CYAN << this->contacts[i].getTitle(j) << RESET << this->contacts[i].getInfo(j) << std::endl;
	}
	else
		std::cout << RED << "The contact you chose is not settled" << RNL;
	this->menuSelector();
	return;
}

void	PhoneBook::searchContact(){
	std::string	input;

	this->displayAgenda();
	std::cout << "Select a number: ";
	if (!std::getline (std::cin, input, '\n'))
		return;
	if ((input[0] >= '1' && input[0] <= '8') && input.length() == 1)
		this->displayContact(input);
	else
	{
		std::cout << RED << "The index you introduced is not correct" << RNL;
		this->searchContact();
	}
	return;
}

void	PhoneBook::menuSelector(){
	std::cout << std::endl << BLUE << "*WELCOME TO THE MENU OF YOUR PHONEBOOK*" << RNL << "Please, select an option:" << std::endl;
	std::cout << "- ADD" << std::endl << "- SEARCH" << std::endl << "- EXIT" << std::endl << std::endl;
	return ;
}

static int	fullTabs(std::string data)
{
	for (int i = 0; i < (int)data.length(); i++)
	{
		if (data[i] < 32)
			return (1);
	}
	for (int i = 0; i < (int)data.length(); i++)
	{
		if (data[i] != 32)
			return (0);
	}
	return (1);
}

void	PhoneBook::fillFields(){
	std::string	data[5];

	for (int i = 0; i < 5; i++)
	{
		std::cout << CYAN << this->contacts[0].getTitle(i) << RESET;
		if (!std::getline(std::cin, data[i], '\n'))
			return ;
		if (data[i].empty() || fullTabs(data[i]) == 1)
		{
			std::cout << RED << "You can't have an empty field or invalid chars!" << RNL;
			i--;
		}
		else if (i == 3 && (!this->isAllDigit(data[i])))
		{
			std::cout << RED << "The phone number must be numeric!" << RNL;
			i--;
		}
	}
	this->addContact(data);
	return ;
}
