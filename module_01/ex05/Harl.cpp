#include "Harl.hpp"

Harl::Harl(){
	std::cout << BRED << "Harl has been created!!" << RNL;
}

Harl::~Harl(){
	std::cout << BRED << "Harl has been horrifically killed" << RNL;
}

void	Harl::debug(void){
	std::cout << "When ducks are borned, they imprint on the first animal they see. They will consider it their mother!!" << std::endl;
}

void	Harl::info(void){
	std:cout << "Even if this animal was a crocodile, the little ducks would love it and follow it, even if that means they're going to die" << std::endl;
}

void	Harl::warning(void){
	std::cout << "Oh no little duckie, don't approach to that crocodile, it's not your real mom!!" << std::endl;
}

void	Harl::error(void){
	std::cout << "... and that's how mother nature works. Goodbye little one :(" << std::endl;
}

void	Harl::complain(std::string level){
	if (level == DEBUG || level == INFO || level == WARNING || level == ERROR)
	{
		for ()
	}
	return ;
}
