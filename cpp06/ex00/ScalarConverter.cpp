#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter&){}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& )
{
	return *this;
}

ScalarConverter::~ScalarConverter(){}

bool	isInteger(const std::string& str)
{
	if (str.empty())
		return false;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.size())
	{
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool	isFloat(const std::string& str)
{
	if (str.empty())
		return false;
	int dot = 0;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.size() - 1)
	{
		if (str[i] == '.')
			dot++;
		else if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return dot == 1 && str[i] == 'f';
}

bool	isDouble(const std::string& str)
{
	if (str.empty())
		return false;
	int dot = 0;
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < str.size())
	{
		if (str[i] == '.')
			dot++;
		else if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return dot == 1;
}

bool isPseudoLiteral(const std::string& str) {
	return str == "-inff" || str == "+inff" || str == "nanf" ||
		str == "-inf" || str == "+inf" || str == "nan" ;
}

void	ScalarConverter::convert(const std::string& str)
{
	// Pseudo Literal
	if (isPseudoLiteral(str)) {
		float f = std::stof(str);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return;
	}

	// char
	if (str.length() == 1 && !std::isdigit(str[0]))
	{
		char c = str[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	// integer or double or float
	if (isInteger(str) || isDouble(str) || isFloat(str)) {
		double value = std::strtod(str.c_str(), nullptr);
		if (value >= 32 && value <= 126)
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		else
				std::cout << "char: Non displayable" << std::endl;
		if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	} else {
		std::cout << "int: impossible" << std::endl;
	}
		if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
		if (value > std::numeric_limits<double>::max() || value < -std::numeric_limits<double>::max()) {
			std::cout << "double: impossible" << std::endl;
		} else {
			std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
		}
		return;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}