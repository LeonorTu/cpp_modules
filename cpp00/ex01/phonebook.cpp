/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:46:26 by jtu               #+#    #+#             */
/*   Updated: 2024/09/05 16:20:53 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::add(void)
{
	while (true)
	{
		std::cout << "Enter first name:";
		std::getline(std::cin, first_name)
	}
}

void	Phonebook::search(void)
{

}

int	main()
{
	Phonebook	book;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			book.add();
		else if (cmd == "SEARCH")
			book.search();
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}
