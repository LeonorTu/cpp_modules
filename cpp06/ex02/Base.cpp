#include "Base.hpp"

Base::Base()
{
	std::cout << "Base default constructor called" << std::endl;
}


Base::Base(const Base& other)
{
	std::cout << "Base copy constructor called" << std::endl;
	//value = other.value;
}


Base& Base::operator=(const Base& other)
{
	std::cout << "Base copy assignment operator called" << std::endl;
	// if (this != &other)

	// return *this;
}

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}