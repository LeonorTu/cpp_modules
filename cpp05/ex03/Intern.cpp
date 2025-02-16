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

AForm* Intern::createShrubbery(const std::string& target) {
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) {
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return new PresidentialPardonForm(target);
}

Intern::InvalidFormException::InvalidFormException(const std::string& message): message_(message) {}

const char* Intern::InvalidFormException::what() const noexcept
{
	return message_.c_str();
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm* (Intern::*formCreators[])(const std::string&) ={&Intern::createShrubbery, &Intern::createRobotomy,&Intern::createPresidential};
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			return (this->*formCreators[i])(target);
		}
	}
	throw InvalidFormException("Invalid Form");
}
