#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();
		static void convert(const std::string& str);
};

#endif