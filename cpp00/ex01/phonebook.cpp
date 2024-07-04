/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:46:26 by jtu               #+#    #+#             */
/*   Updated: 2024/07/04 19:34:10 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	phonebook	book;
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