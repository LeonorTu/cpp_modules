#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	
	std::cout << "==== TEST 1 ====" << std::endl;
	try {
		Bureaucrat	b;
		Form		f;
		b.signForm(f);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "==== TEST 2 ====" << std::endl;
	try {
		Bureaucrat	b1("Amy", 5);
		Form		f1("Form1", 4, 2);
		b1.signForm(f1);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "==== TEST 3 ====" << std::endl;
	try {	
		Bureaucrat	b2("Bob", 30);
		Form 		f2("Form2", 42, 3);
		b2.signForm(f2);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "==== TEST 4 ====" << std::endl;
	try {
		Bureaucrat	b3("Charlie", 0);
		Form		f3("Form3", 8, 100);
		b3.signForm(f3);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "==== TEST 5 ====" << std::endl;
	try {
		Bureaucrat	b4("David", 151);
		Form		f4("Form4", 8, 100);
		b4.signForm(f4);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

}