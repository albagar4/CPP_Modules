#include "Contact.hpp"

std::string	Contact::getTitle(int i) const{
	return (this->_title[i]);
}

std::string	Contact::getInfo(int i) const{
	return (this->_info[i]);
}

void	Contact::setInfo(std::string data[5]){
	for (int i = 0; i < 5; i++)
		this->_info[i] = data[i];
	return;
}

Contact::Contact(){
	std::cout << "Calling contact constructor" << std::endl;
	this->_title[0] = "First name: ";
	this->_title[1] = "Last name: ";
	this->_title[2] = "Nickname: ";
	this->_title[3] = "Phone Number: ";
	this->_title[4] = "Darkest Secret: ";
	return;
}

Contact::~Contact(){
	std::cout << "Calling contact destructor" << std::endl;
	return;
}

bool	Contact::empty(){
	for (int i = 0; i < 5; i++)
	{
		if (this->_info[i].empty())
			return (true);
	}
	return (false);
}
