#include "Span.hpp"

Span::Span() : maxSize(0) {}

Span::Span(unsigned int N) : maxSize(N) {}

Span::Span(const Span &other)
    : maxSize(other.maxSize), numbers(other.numbers) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    maxSize = other.maxSize;
    numbers = other.numbers;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int nbr) {
  if (numbers.size() >= maxSize)
    throw std::out_of_range("Span is full, can't take more number");
  numbers.push_back(nbr);
}

void Span::addNumbers(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end) {
  if ((numbers.size() + std::distance(begin, end)) > maxSize)
    throw std::out_of_range("Too many numbers, span will be full");
  numbers.insert(numbers.end(), begin, end);
}

long long Span::shortestSpan() {
  if (numbers.size() < 2)
    throw std::logic_error("Not enough numbers to find a span");
  std::vector<int> sortedNumbers = numbers;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());

  long long shortest = std::numeric_limits<long long>::max();
  for (size_t i = 1; i < sortedNumbers.size(); ++i) {
    long long span = sortedNumbers[i] - sortedNumbers[i - 1];
    if (span < shortest)
      shortest = span;
  }
  return shortest;
}

long long Span::longestSpan() {
  if (numbers.size() < 2)
    throw std::logic_error("Not enough numbers to find a span");
  int min = *std::min_element(numbers.begin(), numbers.end());
  int max = *std::max_element(numbers.begin(), numbers.end());
  return static_cast<long long>(max) - static_cast<long long>(min);
}