#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "test: " << value; //
	std::cout << "Int constructor called" << std::endl;
	this->value = n << this->fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	float	rounded = roundf((value * (1 << this->fractionalBits)));
	this->value = static_cast<int>(rounded);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	value = other.value;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->value = other.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits( int const raw ){
	value = raw;
}

float	Fixed::toFloat( void ) const
{
	return static_cast<float>(value) / (1 << fractionalBits);
}

int	Fixed::toInt( void ) const
{
	return value >> fractionalBits;
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
}