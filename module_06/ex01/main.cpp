#include "Serializer.hpp"

void printData(Data *data){
	std::cout << "Data->type: " << data->type << std::endl;
	std::cout << "Data->nbr: " << data->nbr << std::endl;
	std::cout << "Data->fnbr: " << data->fnbr << std::endl;
}

int main(void){
	Data *test = new Data;
	test->type = "first_test";
	test->nbr = 32;
	test->fnbr = 5.5;

	printData(test);
	uintptr_t raw = Serializer::serialize(test);
	test = Serializer::deserialize(raw);
	printData(test);

	delete test;
	return (0);
}
