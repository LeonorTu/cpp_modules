#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){}

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
		str == "-inf" || str == "+inf" || str == "nan";
}


void	ScalarConverter::convert(const std::string& str)
{
	// Pseudo Literal
	if (isPseudoLiteral(str)) {
		std::string fstr = str;
		std::string dstr = str;
		if (str == "+inff" || str == "-inff" || str == "nanf")
		{
			fstr = fstr.substr(0, fstr.length() - 1);
		}
		if (str == "+inf" || str == "-inf" || str == "nan") {
			dstr = str + 'f';
		}
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << fstr << std::endl;
		std::cout << "double: " << dstr << std::endl;
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

	// integer
	if (isInteger(str)) {
		long value = std::strtol(str.c_str(), nullptr, 10);
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: overflow" << std::endl;
			std::cout << "float: overflow" << std::endl;
			std::cout << "double: overflow" << std::endl;
			return;
		}
		int intValue = static_cast<int>(value);
		if (intValue >= 32 && intValue <= 126)
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << intValue << std::endl;
		std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
		return;
	}

	// float
	if (isFloat(str)) {
		float floatValue = std::strtof(str.c_str(), nullptr);
		int intValue = static_cast<int>(floatValue);
		if (intValue >= 32 && intValue <= 126)
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
		return;
	}

	// double
	if (isDouble(str)) {
		double doubleValue = std::strtod(str.c_str(), nullptr);
		int intValue = static_cast<int>(doubleValue);
		if (intValue >= 32 && intValue <= 126)
			std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
		std::cout << "float: " << static_cast<float>(doubleValue) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
		return;
	}

	std::cout << "Error: Invalid input." << std::endl;
}