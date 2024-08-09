#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

#define RED    "\033[0;31m"
#define BRED    "\033[1;31m"
#define CYAN    "\033[1;36m"
#define RESET    "\033[0m"
#define RNL    "\033[0m\n"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GRAY "\033[1;30m"
#define PURPLE "\033[35m"
#define LGRAY "\033[0;37m"
#define BOLD "\033[1;37m"

int main(void){
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPtr = &string;
    std::string &stringRef = string;

    std::cout << "Memory address of string: " << RED << &string << RNL;
    std::cout << "Memory address of stringPtr: " << RED << stringPtr << RNL;
    std::cout << "Memory address of stringRef: " << RED << &stringRef << RNL << std::endl;

    std::cout << "Value of string: " << BLUE << string << RNL;
    std::cout << "Value pointed to by stringPtr: " << BLUE << *stringPtr << RNL;
    std::cout << "Value pointed to by stringRef: " << BLUE << stringRef << RNL;
    return (0);
}
