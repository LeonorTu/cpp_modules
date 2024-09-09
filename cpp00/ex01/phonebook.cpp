/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:46:26 by jtu               #+#    #+#             */
/*   Updated: 2024/09/09 18:41:52 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Phonebook::add(void)
{
	std::string	input;

	while (true)
	{
		std::cout << "Enter first name:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty())
			std::cout << "Input can't be empty. Please try agian" << std::endl;
		else
		{
			contacts[current_index].set_first_name(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter last name:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty())
			std::cout << "Input can't be empty. Please try agian" << std::endl;
		else
		{
			contacts[current_index].set_last_name(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter nick name:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty())
			std::cout << "Input can't be empty. Please try agian" << std::endl;
		else
		{
			contacts[current_index].set_nick_name(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter phone number:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty())
			std::cout << "Input can't be empty. Please try agian" << std::endl;
		else
		{
			contacts[current_index].set_phone_number(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter darkest secret:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty())
			std::cout << "Input can't be empty. Please try agian" << std::endl;
		else
		{
			contacts[current_index].set_darkest_secret(input);
			break;
		}
	}
	current_index = (current_index + 1) % 8;
	std::cout << "Contact added successfully!" << std::endl;
}

std::string	truncate_string(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	return (str);
}

void	Phonebook::display_contacts(void)
{
	int	i;

	i = 0;
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;
	while (i < 8)
	{
		if (contacts[i].get_first_name().empty())
			break;
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << truncate_string(contacts[i].get_first_name()) << "|"
				<< std::setw(10) << truncate_string(contacts[i].get_last_name()) << "|"
				<< std::setw(10) << truncate_string(contacts[i].get_nick_name()) << std::endl;
		i++;
	}
}


void	Phonebook::search(void)
{
	std::string	input;
	int	index;

	display_contacts();
	while (true)
	{
		std::cout << "Enter the index of the contact or enter -1 to quit" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		std::istringstream iss(input);; //something wrong here
		if (!(iss >> index) || !iss.eof())
		{
			std::cout << "Invalid index. Please try again!" << std::endl;
			continue ;
		}
		std::cout << "index:" << index;
		if (index >= 0 && index <= 7 && !contacts[index].get_first_name().empty())
		{
			std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
			std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
			std::cout << "Nickname: " << contacts[index].get_nick_name() << std::endl;
			std::cout << "Phone Number: " << contacts[index].get_phone_number()<< std::endl;
			std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
			break;
		}
		else
			std::cout << "Invalid index. Please try again!" << std::endl;
	}
}

int	main()
{
	Phonebook	book;
	std::string	cmd;

	while (true)
	{
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break ;
		if (cmd == "ADD")
			book.add();
		else if (cmd == "SEARCH")
			book.search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Please try again!" << std::endl;
	}
	return (0);
}
