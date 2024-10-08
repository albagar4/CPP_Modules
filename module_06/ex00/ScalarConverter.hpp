#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

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

class ScalarConverter{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &scalarconverter);
	ScalarConverter &operator=(const ScalarConverter &scalarconverter);
	~ScalarConverter();
	static void convert(std::string param);
};

bool ft_is_char(std::string param);
bool ft_is_int(std::string param);
bool ft_is_float(std::string param);
bool ft_is_double(std::string param);
void convert_to_char(std::string param);
void convert_to_int(std::string param);
void convert_to_float(std::string param);
void convert_to_double(std::string param);
void print_error(std::string param);

typedef void (*pointerConverter)(std::string param);
typedef bool (*pointerChecker)(std::string param);

#endif