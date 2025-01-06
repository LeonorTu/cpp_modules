#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other){}

Cat::~Cat(){}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
