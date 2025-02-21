#pragma once

#include <iostream>
#include <vector>

class Span
{
	private:
		unsigned int maxSize;
		std::vector<int> numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int nbr);
		int shortestSpan();
		int longestSpan();
};
