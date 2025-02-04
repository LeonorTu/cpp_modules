#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string& string, int number): name(string)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException("Grade is too high!");
	else if (grade > 150)
		throw GradeTooLowException("Grade is too low!");
	grade = number;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat" << name << " destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return name;
}

int	Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException("Grade can't be higher!");
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException("Grade can't be lower!");
	grade++;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message): message(message) {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return message.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message): message(message) {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return message.c_str();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}