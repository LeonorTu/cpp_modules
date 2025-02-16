#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}


Serializer::Serializer(const Serializer& other)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	//value = other.value;
}


Serializer& Serializer::operator=(const Serializer& other)
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	// if (this != &other)

	// return *this;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}