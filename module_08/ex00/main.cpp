#include "easyfind.hpp"

int main(void) {
	{
		std::vector<int> vec;

		int arr[] = {7, 14, -2, 89};
		vec.assign(arr, arr + 4);
		
		try {
			easyfind(vec, -2);
			easyfind(vec, 3);
		}
		catch (const std::runtime_error &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::list<int> lst;

		lst.push_back(10);
		lst.push_back(20);
		lst.push_back(30);
		lst.push_back(40);

		try {
			easyfind(lst, 30);
			easyfind(lst, 50);
		}
		catch (const std::runtime_error &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
    return 0;
}
