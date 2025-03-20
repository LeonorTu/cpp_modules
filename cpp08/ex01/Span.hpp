#pragma once

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Span {
public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();
  void addNumber(int nbr);
  void addNumbers(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end);
  long long shortestSpan();
  long long longestSpan();

private:
  unsigned int maxSize;
  std::vector<int> numbers;
};
