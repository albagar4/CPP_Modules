#include "Harl.hpp"

Harl::Harl(){
	std::cout << BRED << "Harl has been created!!" << RNL;
}

Harl::~Harl(){
	std::cout << BRED << "Harl has been horrifically killed" << RNL;
}

void	Harl::debug(void){
	std::cout << "When ducks are born, they imprint on the first animal they see. They will consider it their mother!!" << std::endl;
}

void	Harl::info(void){
	std::cout << "Even if this animal was a crocodile, the little ducks would love it and follow it, even if that means they're going to die" << std::endl;
}

void	Harl::warning(void){
	std::cout << "Oh no little duckie, don't approach to that crocodile, it's not your real mom!!" << std::endl;
}

void	Harl::error(void){
	std::cout << "... and that's how mother nature works. Goodbye little one :(" << std::endl;
}

void	Harl::complain(std::string level){
	functionPointer arrayList[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	arrayStr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (arrayStr[i] == level)
		{
			for (int j = i; j < 4; j++)
				(this->*arrayList[j])();
			break ;
		}
	}
	return ;
}
