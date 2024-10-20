#include "./RPN.hpp"

bool correctChar(char c) {
	if (!isdigit(c) && c != '+' && c != '-' && c != '*'
		&& c != '/' && c != ' ' && c != '	')
		return (false);
	return (true);
}

float evaluatePhase(float first, float second, char c) {
	if (c == '+')
		return (first + second);
	else if (c == '-')
		return (first - second);
	else if (c == '*')
		return (first * second);
	return (first / second);
}

int evaluateRPN(char *argv) {
	std::stack<float> nbrs;
	float result = 0;

	if (strlen(argv) == 1 && isdigit(argv[0])) {
		std::cout << argv[0] << std::endl;
		return (0);
	}
	for (long unsigned int i = 0; i < strlen(argv); i++) {
		if (!correctChar(argv[i])) {
			std::cout << "Error: invalid character: " << argv[i] << std::endl;
			return (-1);
		}
		if (isdigit(argv[i])) {
			if (argv[i + 1] != ' ' && argv[i + 1] != '	' && argv[i + 1] != '\0') {
				std::cout << "Error: bad format. Each char must be separated between spaces or tabs, nbrs only from 0 to 9" << std::endl;
				return (-1);
			}
			else
				nbrs.push(atof(&argv[i]));
		}
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/') {
			if (nbrs.empty() || nbrs.size() < 2 || (argv[i + 1] != ' ' && argv[i + 1] != '	' && argv[i + 1] != '\0')) {
				std::cout << "Error: bad format. Operators must be placed after the values and followed by space or tab" << std::endl;
				return (-1);
			}
			float second = nbrs.top();
			nbrs.pop();
			float first = nbrs.top();
			nbrs.pop();
			if (argv[i] == '/' && (first == 0 || second == 0)) {
				std::cout << "Error: divisions by 0 are not allowed" << std::endl;
				return (-1);
			}
			result = evaluatePhase(first, second, argv[i]);
			nbrs.push(result);
		}
	}
	if (nbrs.size() != 1) {
		if (nbrs.empty())
			std::cout << "Error: string without parameters" << std::endl;
		else
			std::cout << "Error: too many nbrs to evaluate" << std::endl;
		return (-1);
	}
	std::cout << result << std::endl;
	return (0);
}
