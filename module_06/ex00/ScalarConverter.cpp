#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	// std::cout << "ScalarConverter: Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(){
	// std::cout << "ScalarConverter: Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter){
	(void)scalarconverter;
	// std::cout << "ScalarConverter: Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarconverter){
	(void)scalarconverter;
	// std::cout << "ScalarConverter: Copy assignment operator called" << std::endl;
	return (*this);
}

bool ft_is_char(std::string param){
	if (param.length() == 1 && !std::isdigit(param[0]))
		return (true);
	return (false);
}

bool ft_is_int(std::string param){
	int32_t i = 0;
	char *endptr;

	if (param[0] == '-' || param[0] == '+')
		i = 1;
	for (int j = i; j < (int)param.length(); j++)
	{
		if (!isdigit(param[j]))
		{
			if (param[j] == '.')
			{
				for (int k = j + 1; k < (int)param.length(); k++)
					if (param[k] != '0')
						return (false);
			}
			else
				return (false);
		}
	}

	int64_t result = strtol(param.c_str(), &endptr, 10);
	return (!(result < INT32_MIN || result > INT32_MAX));
}

bool ft_is_float(std::string param){
	int i = 0;
	int dot = 0;
	char *endptr;

	if (param[0] == '-' || param[0] == '+')
		i = 1;
	if (param[i] == '.')
		return (false);
	for (int j = i; j < (int)param.length(); j++)
	{
		if (param[j] == '.' && dot == 0)
			dot = 1;
		else if (!isdigit(param[j]) || param[param.length() - 1] != 'f')
			return (false);
	}

	int64_t result = strtol(param.c_str(), &endptr, 10);
	return (!(result < INT32_MIN || result > INT32_MAX));
}

bool ft_is_double(std::string param){
	int i = 0;
	int dot = 0;

	if (param[0] == '-' || param[0] == '+')
		i = 1;
	if (param[i] == '.')
		return (false);
	for (int j = i; j < (int)param.length(); j++)
	{
		if (param[j] == '.' && dot == 0)
			dot = 1;
		else if (!isdigit(param[j]))
			return (false);
	}
	return (true);
}

void convert_to_char(std::string param){
	char a = param[0];

	if (param[0] >= 32 && param[0] <= 126)
		std::cout << "char: " << a << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << static_cast<float>(a) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
	return ;
}

void convert_to_int(std::string param){
	int a = atoi(param.c_str());

	if (a >= 32 && a <= 126)
		std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << a << std::endl;
	std::cout << "float: " << static_cast<float>(a) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << ".0" << std::endl;
	return ;
}

void convert_to_float(std::string param){
	float a = std::atof(param.c_str());

	if (a >= 32 && a <= 126)
		std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(a) << std::endl;
	std::cout << "float: " << a << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(a) << std::endl;
	return ;
}

void convert_to_double(std::string param){
	double a = std::atof(param.c_str());

	if (a >= 32 && a <= 126)
		std::cout << "char: '" << static_cast<char>(a) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (a >= INT32_MIN && a <= INT32_MAX)
		std::cout << "int: " << static_cast<int>(a) << std::endl << "float: " << static_cast<float>(a) << "f" << std::endl;
	else
		std::cout << "int: Out of limits" << std::endl << "float: Out of limits" << std::endl;
	std::cout << "double: " << a << std::endl;
	return ;
}

void print_error(std::string param){
	if (param == "nan" || param == "nanf" || param == "-inf"
		|| param == "+inf" || param == "-inff" || param == "+inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		if (param == "-inf" || param == "-inff")
			std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
		else if (param == "+inf" || param == "+inff")
			std::cout << "float: +inff" << std::endl << "double: +inf" << std::endl;
		else
			std::cout << "float: nanf" << std::endl << "double: nan" << std::endl;
	}
	else
	{
		std::cout << "char: Cannot convert" << std::endl;
		std::cout << "int: Cannot convert" << std::endl;
		std::cout << "float: Cannot convert" << std::endl;
		std::cout << "double: Cannot convert" << std::endl;
	}
}

void ScalarConverter::convert(std::string param){
	pointerChecker boolArray[4] = {&ft_is_char, &ft_is_int, &ft_is_float, &ft_is_double};
	pointerConverter convertArray[4] = {&convert_to_char, &convert_to_int, &convert_to_float, &convert_to_double};

	for (int i = 0; i < 4; i++)
	{
		if (boolArray[i](param) == true)
		{
			convertArray[i](param);
			return ;
		}
	}
	print_error(param);
	return ;
}
