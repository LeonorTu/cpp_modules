#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();  // Should succeed (grade becomes 1)
        std::cout << b1 << std::endl;

        b1.incrementGrade();  // Should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade();  // Should succeed (grade becomes 150)
        std::cout << b2 << std::endl;

        b2.decrementGrade();  // Should throw GradeTooLowException
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 0);  // Invalid grade, should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught during instantiation: " << e.what() << std::endl;
    }

    return 0;
}