#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void) other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm*	makeForm(const std::string& formName, const std::string& targrt)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int formIndex = 0;

	switch (formIndex)
	{
		case 0:
		case 1:
		case 2:
	}
	std::cout << "Intern creates" << formNames[formIndex] << std::endl;
}