#define BRED    "\033[1;31m"
#define RNL    "\033[0m\n"

#include <iostream>
#include <stdlib.h>

class Base{
	public:
		virtual ~Base() {};
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

Base *generate(void){
	int random = std::rand();

	if (random % 2)
		return (new A());
	else if (random % 3)
		return (new B());
	else
		return (new C());
}

void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer to A Class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer to B Class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer to C Class" << std::endl;
	else
		std::cout << "Unverifiable" << std::endl;
}

void identify(Base &p){
	try {
		A &test = dynamic_cast<A&>(p);
		(void)test;
		std::cout << "Reference to A Class" << std::endl;
	}
	catch (std::exception &e) {
		try {
			B &test = dynamic_cast<B&>(p);
			(void)test;
			std::cout << "Reference to B Class" << std::endl;
		}
		catch (std::exception &e) {
			try {
				C &test = dynamic_cast<C&>(p);
				(void)test;
				std::cout << "Reference to C Class" << std::endl;
			}
			catch (std::exception &e) {
				std::cout << "Unverifiable";
			}
		}
	}
}

int main(void){
	std::cout << BRED << "Test with Pointers" << RNL;
	for (int i = 0; i < 15; i++)
	{
		Base *test = generate();
		identify(test);
	}
	std::cout << std::endl << BRED << "Test with References" << RNL;
	for (int i = 0; i < 15; i++)
	{
		Base *test = generate();
		identify(*test);
	}
	return (0);
}
