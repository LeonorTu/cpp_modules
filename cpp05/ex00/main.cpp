#include "Bureaucrat.hpp"

int main() {

    std::cout << "==== TEST 1 ====" << std::endl;
    try {
        Bureaucrat b1("Amy", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();  // Should succeed (grade becomes 1)
        std::cout << b1 << std::endl;

        b1.incrementGrade();  // Should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "==== TEST 2 ====" << std::endl;
    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();  // Should succeed (grade becomes 150)
        std::cout << b2 << std::endl;

        b2.decrementGrade();  // Should throw GradeTooLowException
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "==== TEST 3 ====" << std::endl;
    try {
        Bureaucrat b3("Charlie", 0);  // Invalid grade, should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}