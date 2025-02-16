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

Intern::InvalidFormException::InvalidFormException(const std::string& message): message_(message) {}

const char* Intern::InvalidFormException::what() const noexcept
{
	return message_.c_str();
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int formIndex = -1;
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			formIndex = i;
			break;
		}
	}
	switch (formIndex)
	{
		case 0:
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			throw InvalidFormException("Invalid Form");
	}
}
