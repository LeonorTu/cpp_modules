#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int	main(void) {
	std::cout << "==== TEST 1 ====" << std::endl;
	try {
		ShrubberyCreationForm sForm1("Amy");
		Bureaucrat arborist1("Arborist1", 137);
		arborist1.signForm(sForm1);
		arborist1.executeForm(sForm1);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 2 ====" << std::endl;
	try {
		ShrubberyCreationForm sForm2("Bob");
		Bureaucrat arborist2("Arborist2", 140);
		arborist2.signForm(sForm2);
		arborist2.executeForm(sForm2);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 3 ====" << std::endl;
	try {
		RobotomyRequestForm rForm("Charlie");
		Bureaucrat robot("Robot", 40);
		robot.signForm(rForm);
		robot.executeForm(rForm);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 4 ====" << std::endl;
	try {
		PresidentialPardonForm pForm1("David");
		Bureaucrat president1("President1", 1);
		president1.signForm(pForm1);
		president1.executeForm(pForm1);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 5 ====" << std::endl;
	try {
		PresidentialPardonForm pForm2("Flora");
		Bureaucrat president2("President", 0);
		president2.signForm(pForm2);
		president2.executeForm(pForm2);
	} catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}