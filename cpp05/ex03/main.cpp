#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void) {
	std::cout << "==== TEST 1 ====" << std::endl;
	try {
		Intern intern1;
		Bureaucrat director("Director", 45);
		AForm* rrf = intern1.makeForm("robotomy request", "President");
		director.signForm(*rrf);
		director.executeForm(*rrf);
		delete rrf;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::cout << "==== TEST 2 ====" << std::endl;
	try {
		Intern intern2;
		Bureaucrat president("President", 1);
		AForm* ppf = intern2.makeForm("presidential pardon", "Manager");
		president.signForm(*ppf);
		president.executeForm(*ppf);
		delete ppf;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 3 ====" << std::endl;
	try {
		Intern intern3;
		Bureaucrat worker("Worker", 145);
		AForm* scf = intern3.makeForm("shrubbery creation", "Team Lead");
		worker.signForm(*scf);
		worker.executeForm(*scf);
		delete scf;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "==== TEST 4 ====" << std::endl;
	try {
		Intern intern4;
		Bureaucrat teamLead("Team Lead", 70);
		AForm* rf = intern4.makeForm("random", "Employee");
		teamLead.signForm(*rf);
		teamLead.executeForm(*rf);
		delete rf;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}