#include "AForm.hpp"

AForm::AForm(): name_("Default AForm"), isSigned_(false), gradeToSign_(42), gradeToExecute_(42)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute, const std::string& target): name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute), target(target)
{
	std::cout << "AForm " << name_ << " parameterized constructor called" << std::endl;
	if (gradeToSign < 1)
		throw GradeTooHighException("GradeToSign is too high!");
	else if (gradeToSign > 150)
		throw GradeTooLowException("GradeToSign is too low!");
	if (gradeToExecute < 1)
		throw GradeTooHighException("GradeToExecute is too high!");
	else if (gradeToExecute > 150)
		throw GradeTooLowException("GradeToExecute is too low!");
}

AForm::AForm(const AForm& other): name_(other.name_), isSigned_(other.isSigned_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_)
{
	std::cout << "AForm " << name_ << " copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned_ = other.isSigned_;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << name_ << " destructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return name_;
}

bool AForm::getIsSigned() const
{
  return isSigned_;
}

int AForm::getGradeToSign() const
{
  return gradeToSign_;
}

int AForm::getGradeToExecute() const
{
  return gradeToExecute_;
}

std::string AForm::getTarget() const
{
	return target;
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message): message_(message) {}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return message_.c_str();
}

AForm::GradeTooHighException::GradeTooHighException(const std::string& message): message_(message) {}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return message_.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string& message): message_(message) {}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return message_.c_str();
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() <= gradeToSign_)
    isSigned_ = true;
  else
    throw GradeTooLowException("grade is too low to sign the form!");
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << "AForm:" << form.getName() << std::endl
      << "Is signed:" << form.getIsSigned() << std::endl
      << "Grade to sign:    " << form.getGradeToSign() << std::endl
			<< "Grade to execute: " << form.getGradeToExecute();
	return os;
}