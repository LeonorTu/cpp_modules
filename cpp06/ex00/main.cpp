#include "ScalarConverter.hpp"

int main() {
	std::cout << "Test 1: Integer 0\n";
	ScalarConverter::convert("0");

	std::cout << "\nTest 2: Integer 42\n";
	ScalarConverter::convert("42");

	std::cout << "\nTest 2: Integer 2147483647\n";
	ScalarConverter::convert("2147483647");

	std::cout << "\nTest 3: Float 4.2f\n";
	ScalarConverter::convert("4.2f");

	std::cout << "\nTest 4: Float 42.0f\n";
	ScalarConverter::convert("42.0f");

	std::cout << "\nTest 5: Double 4.2\n";
	ScalarConverter::convert("4.2");

	std::cout << "\nTest 6: Double 42.42\n";
	ScalarConverter::convert("42.42");

	std::cout << "\nTest 7: Char a\n";
	ScalarConverter::convert("a");

	std::cout << "\nTest 8: Char Z\n";
	ScalarConverter::convert("Z");

	std::cout << "\nTest 9: Pseudo-literal +inf\n";
	ScalarConverter::convert("+inf");

	std::cout << "\nTest 10: Pseudo-literal nan\n";
	ScalarConverter::convert("nan");

	std::cout << "\nTest 11: Pseudo-literal -inff\n";
	ScalarConverter::convert("-inff");

	std::cout << "\nTest 12: Invalid input hello\n";
	ScalarConverter::convert("hello");

	std::cout << "\nTest 13: Invalid input nan.0f\n";
	ScalarConverter::convert("nan.0f");

	std::cout << "\nTest 13: Invalid input nan.0f\n";
	ScalarConverter::convert("nan.0f");

	std::cout << "\nTest 13: Invalid input 2147483648\n";
	ScalarConverter::convert("2147483648");

	std::cout << "\nTest 13: Invalid input 56456465465464655465456456445184848641531655498897489.0f\n";
	ScalarConverter::convert("56456465465464655465456456445184848641531655498897489.0f");

	return 0;
}
