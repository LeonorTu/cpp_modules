#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments\n";
		return (1);
	}
	Harl	harl;
	harl.complain(argv[1]);
	return (0);
}