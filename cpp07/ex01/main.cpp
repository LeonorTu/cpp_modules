
#include <iostream>
#include "iter.hpp"

int main() {

	std::cout << "==== TEST 1 ====" << std::endl;
	int intArray[] = {-445, 2484, 35, 45266, 50};
	size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);
	std::cout << "Integer array elements: ";
	iter(intArray, intArrayLen , [](int x) { std::cout << x << " "; });
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 2 ====" << std::endl;
	float floatArray[] = {1.10f, 9.2f, 3.64655f, 5.1545454545454545645464f};
	size_t floatArrayLen = sizeof(floatArray) / sizeof(floatArray[0]);
	std::cout << "Float array elements: ";
	iter(floatArray, floatArrayLen, [](float x) { std::cout << x << " "; });
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 3 ====" << std::endl;
	double doubleArray[] = {45.23, 2.247, 31.60, 14.254564465, 58.15};
	size_t doubleArrayLen = sizeof(doubleArray) / sizeof(doubleArray[0]);
	std::cout << "Double array elements: ";
	iter(doubleArray, doubleArrayLen, [](double x) { std::cout << x << " "; });
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 4 ====" << std::endl;
	char charArray[] = {'*', 'a', ',', '.', 'Z', '$', '@'};
	size_t charArrayLen = sizeof(charArray) / sizeof(charArray[0]);
	std::cout << "Char array elements: ";
	iter(charArray, charArrayLen, [](char x) { std::cout << x << " "; });
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 5 ====" << std::endl;
	std::string stringArray[] = {"Hello", " Wolrd!", "Today", "is", "a", "beautiful", "day", "!", ":D"};
	size_t stringArrayLen = sizeof(stringArray) / sizeof(stringArray[0]);
	std::cout << "String array elements: ";
	iter(stringArray, stringArrayLen, [](std::string x) { std::cout << x << " "; });
	std::cout << std::endl;

	return 0;
}
