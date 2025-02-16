#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137, "default target")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm " << target << " parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << getTarget() << " destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException("Form is not signed! Can't be executed.");
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException("their grade is too low to execute the form");
	std::ofstream file(getTarget() + "_shrubbery");
	if (!file)
		throw std::runtime_error("There's something wrong with creating shrubbery file");
	file << "      *      " << std::endl;
	file << "     ***     " << std::endl;
	file << "    *****    " << std::endl;
	file << "   *******   " << std::endl;
	file << "  *********  " << std::endl;
	file << " *********** " << std::endl;
	file << "     |||     " << std::endl;
	file.close();
}