#include "ScalarConverter.hpp"

// int main() {
// 	std::cout << "Test 1: Integer 0\n";
// 	ScalarConverter::convert("0");

// 	std::cout << "\nTest 2: Integer 42\n";
// 	ScalarConverter::convert("42");

// 	std::cout << "\nTest 3: Integer 2147483647\n";
// 	ScalarConverter::convert("2147483647");

// 	std::cout << "\nTest 4: Float 4.2f\n";
// 	ScalarConverter::convert("4.2f");

// 	std::cout << "\nTest 5: Float 42.0f\n";
// 	ScalarConverter::convert("42.0f");

// 	std::cout << "\nTest 6: Double 4.2\n";
// 	ScalarConverter::convert("4.2");

// 	std::cout << "\nTest 7: Double 42.42\n";
// 	ScalarConverter::convert("42.42");

// 	std::cout << "\nTest 8: Char a\n";
// 	ScalarConverter::convert("a");

// 	std::cout << "\nTest 9: Char *\n";
// 	ScalarConverter::convert("*");

// 	std::cout << "\nTest 10: Pseudo-literal +inf\n";
// 	ScalarConverter::convert("+inf");

// 	std::cout << "\nTest 11: Pseudo-literal nan\n";
// 	ScalarConverter::convert("nan");

// 	std::cout << "\nTest 12: Pseudo-literal -inff\n";
// 	ScalarConverter::convert("-inff");

// 	std::cout << "\nTest 13: Invalid input hello\n";
// 	ScalarConverter::convert("hello");

// 	std::cout << "\nTest 14: Invalid input nan.0f\n";
// 	ScalarConverter::convert("nan.0f");

// 	std::cout << "\nTest 15: Invalid input -nan\n";
// 	ScalarConverter::convert("-nan");

// 	std::cout << "\nTest 16: Integer (overfloat) 2147483648\n";
// 	ScalarConverter::convert("2147483648");

// 	std::cout << "\nTest 17: Float (overflow) 56456465465464655465456456445184848641531655498897489.0f\n";
// 	ScalarConverter::convert("56456465465464655465456456445184848641531655498897489.0f");

// 	std::cout << "\nTest 18: Double 3.5e38\n";
// 	ScalarConverter::convert("3500000000000000000000000000000000000");

// 	std::cout << "\nTest 19: Invalid input 20.5ff\n";
// 	ScalarConverter::convert("20.5ff");

// 	std::cout << "\nTest 18: Invalid input 12.4.5\n";
// 	ScalarConverter::convert("12.4.5");

// 	return 0;
// }

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		std::cout << "Usage: ./convert <input>" << std::endl;
		return 1;
	}
	const std::string input(argv[1]);
	ScalarConverter::convert(input);
}