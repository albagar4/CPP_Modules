#include "./Serializer.hpp"

Serializer::Serializer(){
	// std::cout << "Serializer: Default constructor called" << std::endl;
}

Serializer::~Serializer(){
	// std::cout << "Serializer: Destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &serializer){
	(void)serializer;
	// std::cout << "Serializer: Copy constructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &serializer){
	(void)serializer;
	// std::cout << "Serializer: Copy assignment operator called" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr){
	uintptr_t casted;

	casted = reinterpret_cast<uintptr_t>(ptr);
	return (casted);
}

Data *Serializer::deserialize(uintptr_t raw){
	Data *recasted;

	recasted = reinterpret_cast<Data *>(raw);
	return (recasted);
}
