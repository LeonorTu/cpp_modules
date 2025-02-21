#include "Span.hpp"

Span::Span(): maxSize(0){}

Span::Span(unsigned int N): maxSize(N) {}

Span::Span(const Span& other): numbers(other.numbers), maxSize(other.maxSize){}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int nbr)
{

}
int Span::shortestSpan()
{

}

int Span::longestSpan()
{

}