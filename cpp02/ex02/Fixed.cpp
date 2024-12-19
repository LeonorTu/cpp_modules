#include "Fixed.hpp"

Fixed::Fixed(): value(0){}

Fixed::Fixed(const int n)
{
	this->value = n << this->fractionalBits;
}

Fixed::Fixed(const float n)
{
	float	rounded = roundf((n * (1 << this->fractionalBits)));
	this->value = static_cast<int>(rounded);
}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed& other)
{
	value = other.value;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->value = other.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits(void) const
{
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


bool	Fixed::operator>(const Fixed& other)
{
	return (this->value > other.value);
}

bool	Fixed::operator<(const Fixed& other)
{
	return (this->value < other.value);
}

bool	Fixed::operator>=(const Fixed& other)
{
	return (this->value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other)
{
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed& other)
{
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed& other)
{
	return (this->value != other.value);
}

// arithmetic Fixed::operators
Fixed	Fixed::operator+(const Fixed& other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed&	Fixed::operator++()
{
	++value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	++value;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	--value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	--value;
	return (temp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	return (a.value < b.value) ? a : b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.value < b.value) ? a : b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	return (a.value > b.value) ? a : b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.value > b.value) ? a : b;
}
