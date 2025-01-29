#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(const Animal& other) : type(other.type){}

Animal::~Animal(){}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}