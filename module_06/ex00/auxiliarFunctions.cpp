#include "ScalarConverter.hpp"

bool is_char(std::string param){
	if (param.length() == 1 && !std::isdigit(param[0]))
		return (true);
	return (false);
}

bool is_int(std::string param){
	int32_t i = 0;
	char *endptr;

	if (param[0] == '-' || param[0] == '+')
		i = 1;
	for (int j = i; j < (int)param.length(); j++)
	{
		if (!isdigit(param[j]))
			return (false);
	}

	int64_t result = strtol(param.c_str(), &endptr, 10);
	return (!(result < INT32_MIN || result > INT32_MAX));
}

bool is_float(std::string param){
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

bool is_double(std::string param){
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

	if (dot == 0)
		return (false);
	return (true);
}
