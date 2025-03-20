#include "Span.hpp"

int main() {
  std::cout << "===Original Test===" << std::endl;
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::cout << "\n===Test with one number===" << std::endl;
  try {
    Span sp1 = Span(1);
    sp1.addNumber(5);
    std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\n===Test with no number===" << std::endl;
  try {
    Span sp2 = Span(0);
    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\n===Test with duplicate number===" << std::endl;
  Span sp3 = Span(5);
  sp3.addNumber(5);
  sp3.addNumber(5);
  sp3.addNumber(5);
  sp3.addNumber(5);
  sp3.addNumber(5);
  std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

  std::cout << "\n===Test with int max and int min===" << std::endl;
  Span sp4 = Span(5);
  sp4.addNumber(-2147483648);
  sp4.addNumber(-10);
  sp4.addNumber(0);
  sp4.addNumber(2147483647);
  sp4.addNumber(5);
  std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp4.longestSpan() << std::endl;

  std::cout << "\n===Test with max size span===" << std::endl;
  try {
    Span sp5 = Span(3);
    sp5.addNumber(1);
    sp5.addNumber(2);
    sp5.addNumber(3);
    sp5.addNumber(4); // This should throw an exception
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\n===Test with range of numbers===" << std::endl;
  try {
    Span sp6 = Span(10);
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    sp6.addNumbers(numbers.begin(), numbers.end());
    std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "\n===Test with oversized range of numbers===" << std::endl;
  try {
    Span sp6 = Span(10);
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    sp6.addNumbers(numbers.begin(), numbers.end());
    std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}