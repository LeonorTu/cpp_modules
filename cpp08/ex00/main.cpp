#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <deque>

int main()
{
	std::vector<int> vec = {10, 20, 30, 40, 50};

	try {
		auto it = easyfind(vec, 30);
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		auto it = easyfind(vec, 100); // Not in the vector
		std::cout << "Found in vector: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::list<int> lst = {5, 15, 25, 35, 45};

	try {
		auto it = easyfind(lst, 25);
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		auto it = easyfind(lst, 99); // Not in the list
		std::cout << "Found in list: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::deque<int> deq = {100, 200, 300, 400, 500};
	try {
		auto it = easyfind(deq, 100);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		auto it = easyfind(deq, 2);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}