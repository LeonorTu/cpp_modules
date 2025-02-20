#include <iostream>
#include "Array.hpp"

int main() {
	try {
		std::cout << "Test default constructor\n";
		Array<int> arr1;
		std::cout << "Size of arr1: " << arr1.size() << " (Expected: 0)\n\n";

		std::cout << "Test constructor with size 5\n";
		Array<int> arr2(5);
		std::cout << "Size of arr2: " << arr2.size() << " (Expected: 5)\n";

		std::cout << "Modifying elements in arr2\n";
		for (unsigned int i = 0; i < arr2.size(); ++i) {
			arr2[i] = (i + 8) * i;  // Set values to 0, 9, 20, 33, 48
		}

		std::cout << "arr2 contents: ";
		for (unsigned int i = 0; i < arr2.size(); ++i) {
			std::cout << arr2[i] << " ";
		}
		std::cout << "\n\n";

		std::cout << "Test copy constructor\n";
		Array<int> arr3 = arr2;
		std::cout << "Size of arr3: " << arr3.size() << " (Expected: 5)\n";

		std::cout << "arr3 contents (should match arr2): ";
		for (unsigned int i = 0; i < arr3.size(); ++i) {
			std::cout << arr3[i] << " ";
		}
		std::cout << "\n\n";

		std::cout << "Modifying arr3 (should NOT affect arr2)\n";
		arr3[0] = 99;
		std::cout << "arr3[0]: " << arr3[0] << " (Expected: 99)\n";
		std::cout << "arr2[0]: " << arr2[0] << " (Expected: 0)\n\n";

		std::cout << "Test float array\n";
		Array<float> arr4(7);
		arr4[0] = 5.455;
		arr4[1] = 456.122;
		arr4[2] = 45.45;
		for (unsigned int i = 0; i < arr4.size(); ++i) {
			std::cout << arr4[i] << " ";
		}
		std::cout << "\n\n";

		std::cout << "Test string array\n";
		Array<std::string> arr5(3);
		arr5[0] = "Hello";
		arr5[1] = "World";
		arr5[2] = "!";
		for (unsigned int i = 0; i < arr5.size(); ++i) {
			std::cout << arr5[i] << " ";
		}
		std::cout << "\n\n";

		std::cout << "Test out-of-bounds access\n";
		std::cout << arr5[10] << "\n"; // Should throw exception

	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
