#include "Harl.hpp"
#include <iostream>

void	Harl::debug( void ){
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
		<< "I really do!" << std::endl;
}

void	Harl::info( void ){
	std::cout << "[ INFO ]" << std::endl
	<< "I cannot believe adding extra bacon costs more money." << std::endl
	<< "You didn’t put enough bacon in my burger!" << std::endl
	<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning( void ){
	std::cout << "[ WARNING ]" << std::endl
	<< "I think I deserve to have some extra bacon for free." << std::endl
	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void ){
	std::cout << "[ ERROR ]" << std::endl
	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain( std::string level ){
	void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = -1;
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			levelIndex = i;
			break ;
		}
	}
	switch (levelIndex)
	{
		case -1:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break;
		default:
				for (int i = levelIndex; i < 4; i++){
					(this->*functions[i])();
					std::cout << std::endl;
				}
				break;
	}

}
