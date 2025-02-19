#include <iostream>
#include "whatever.hpp"

int main()
{

	std::cout << "==== TEST 1 ====" << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 2 ====" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 3 ====" << std::endl;
	char c1 = 'A';
	char c2 = 'a';
	std::cout << "before swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "after swap: c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << "min( c1, c2 ) = " << ::min( c1, c2 ) << std::endl;
	std::cout << "max( c1, c2 ) = " << ::max( c1, c2 ) << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 4 ====" << std::endl;
	std::string str1 = "Hello";
	std::string str2 = "Hell";
	std::cout << "before swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	::swap(str1, str2);
	std::cout << "after swap: str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min( str1, str2 ) = " << ::min( str1, str2 ) << std::endl;
	std::cout << "max( str1, str2 ) = " << ::max( str1, str2 ) << std::endl;

	std::cout << std::endl;
	std::cout << "==== TEST 5 ====" << std::endl;
	float num3 = 42.2;
	float num4 = 42.3;
	std::cout << "before swap: num3 = " << num3 << ", num4 = " << num4<< std::endl;
	::swap( num3, num4);
	std::cout << "after swap: num3 = " << num3 << ", num4 = " << num4<< std::endl;
	std::cout << "min( num3, num4) = " << ::min( num3, num4) << std::endl;
	std::cout << "max( num3, num4) = " << ::max( num3, num4) << std::endl;
}