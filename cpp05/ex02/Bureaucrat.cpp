#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_("Default Bureaucrat"), grade_(1)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name), grade_(grade)
{
	std::cout << "Bureaucrat " << name_ << " parameterized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException("Grade is too high!");
	else if (grade > 150)
		throw GradeTooLowException("Grade is too low!");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name_(other.name_), grade_(other.grade_)
{
	std::cout << "Bureaucrat " << name_ << " copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->grade_ = other.grade_;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << name_ << " destructor called" << std::endl;
}

std::string	Bureaucrat::getName() const
{
	return name_;
}

int	Bureaucrat::getGrade() const
{
	return grade_;
}

void Bureaucrat::incrementGrade()
{
	if (grade_ - 1 < 1)
		throw GradeTooHighException("Grade can't be higher!");
	grade_--;
}

void Bureaucrat::decrementGrade()
{
	if (grade_ + 1 > 150)
		throw GradeTooLowException("Grade can't be lower!");
	grade_++;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << " for " << form.getTarget() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << name_ << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}

}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << " for " << form.getTarget() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << name_ << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message): message_(message) {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return message_.c_str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message): message_(message) {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return message_.c_str();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}