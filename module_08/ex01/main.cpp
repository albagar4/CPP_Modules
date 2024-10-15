#include "Span.hpp"

int main(void) {
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		try {
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		int size = 10000;
		int *nbr_list = new int[size];
		Span error_test(10);
		Span test(size);

		for (int i = 0; i < size; i++)
			nbr_list[i] = rand();
		try {
			// error_test.fillSpan(nbr_list, size);
			test.fillSpan(nbr_list, size);
			std::cout << test.shortestSpan() << std::endl;
			std::cout << test.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete [] nbr_list;
	}
	return (0);
}
