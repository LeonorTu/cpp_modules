#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type){}

WrongAnimal::~WrongAnimal(){}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound" << std::endl;
}
