#include "Dog.hpp"

Dog::Dog(): Animal()
{
	type = "Dog";
}

Dog::Dog(const Dog& other): Animal(other){}

Dog::~Dog(){}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
