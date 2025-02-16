#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

class Serializer
{
	private:


	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

};

#endif

