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

void printLevel(std::string level) {
	std::cout << std::endl << "[ " << level << " ]" << std::endl; 
}

void	Harl::complain(std::string level){
	std::string	arrayStr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		if (arrayStr[i] == level)
		{
			switch(i)
			{
				case 0:
					printLevel(arrayStr[0]);
					this->debug();
				case 1:
					printLevel(arrayStr[1]); 
					this->info();
				case 2:
					printLevel(arrayStr[2]);
					this->warning();
				case 3:
					printLevel(arrayStr[3]);
					this->error();
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}
