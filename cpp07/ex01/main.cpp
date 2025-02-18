
#include <iostream>
#include "iter.hpp"

// A sample function to be used with iter
void printElement(int x) {
    std::cout << x << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array elements: ";
    iter(arr, len, printElement);
    std::cout << std::endl;

    return 0;
}
