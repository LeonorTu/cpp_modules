#include "Form.hpp"

Form::Form(): name_("Default Form"), isSigned_(false), gradeToSign_(42), gradeToExecute_(42)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	std::cout << "Form " << name_ << " parameterized constructor called" << std::endl;
	if (gradeToSign < 1)
		throw GradeTooHighException("GradeToSign is too high!");
	else if (gradeToSign > 150)
		throw GradeTooLowException("GradeToSign is too low!");
	if (gradeToExecute < 1)
		throw GradeTooHighException("GradeToExecute is too high!");
	else if (gradeToExecute > 150)
		throw GradeTooLowException("GradeToExecute is too low!");
}

Form::Form(const Form& other): name_(other.name_), isSigned_(other.isSigned_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_)
{
	std::cout << "Form " << name_ << " copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->isSigned_ = other.isSigned_;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form " << name_ << " destructor called" << std::endl;
}

std::string	Form::getName() const
{
	return name_;
}

bool Form::getIsSigned() const
{
  return isSigned_;
}

int Form::getGradeToSign() const
{
  return gradeToSign_;
}

int Form::getGradeToExecute() const
{
  return gradeToExecute_;
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message): message_(message) {}

const char* Form::GradeTooLowException::what() const noexcept
{
	return message_.c_str();
}

Form::GradeTooHighException::GradeTooHighException(const std::string& message): message_(message) {}

const char* Form::GradeTooHighException::what() const noexcept
{
	return message_.c_str();
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
  if (bureaucrat.getGrade() <= gradeToSign_)
    isSigned_ = true;
  else
    throw GradeTooLowException("grade is too low to sign the form!");
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << "Form:" << form.getName() << std::endl
      << "Is signed:" << form.getIsSigned() << std::endl
      << "Grade to sign:    " << form.getGradeToSign() << std::endl
			<< "Grade to execute: " << form.getGradeToExecute();
	return os;
}