#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong nbr of parameters" << std::endl;
		std::cout << "Usage: ./RPN \"<mathematical expression>\"" << std::endl;
	}
	else
		evaluateRPN(argv[1]);
	return (0);
}
