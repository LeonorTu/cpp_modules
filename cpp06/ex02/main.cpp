#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Generate A\n";
			return new A;
		case 1:
			std::cout << "Generate B\n";
			return new B;
		case 2:
			std::cout << "Generate C\n";
			return new C;
	}
	return nullptr;
}

void identify(Base* p)
{
	Base* test = dynamic_cast<A*>(p);
	if (test)
	{
		std::cout << "A\n";
		return;
	}
	test = dynamic_cast<B*>(p);
	if (test)
	{
		std::cout << "B\n";
		return;
	}
	test = dynamic_cast<C*>(p);
	if (test)
	{
		std::cout << "C\n";
		return;
	}
}

void identify(Base& p)
{
	try
	{
		A& test = dynamic_cast<A&>(p);
		(void) test;
		std::cout << "A\n";
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		B& test = dynamic_cast<B&>(p);
		(void) test;
		std::cout << "B\n";
		return ;
	}
	catch(const std::exception& e){}

	try
	{
		C& test = dynamic_cast<C&>(p);
		(void) test;
		std::cout << "C\n";
		return ;
	}
	catch(const std::exception& e){}
}

int main(void)
{

	std::srand(time(0));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Test: " << i + 1 << std::endl;
		Base* random = generate();
		identify(random);
		identify(*random);
		delete random;
	}
}