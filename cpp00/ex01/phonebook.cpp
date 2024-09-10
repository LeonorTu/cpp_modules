/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:46:26 by jtu               #+#    #+#             */
/*   Updated: 2024/09/10 13:53:50 by jtu              ###   ########.fr       */
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
			std::cout << "Input can't be empty. Please try agian!" << std::endl;
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
			std::cout << "Input can't be empty. Please try agian!" << std::endl;
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
			std::cout << "Input can't be empty. Please try agian!" << std::endl;
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
			std::cout << "Input can't be empty. Please try agian!" << std::endl;
		else
		{
			contacts[current_index].set_phone_number(input);
			break;
		}
	}
	while (true)
	{
		std::cout << "Enter the darkest secret:" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.empty())
			std::cout << "Input can't be empty. Please try agian!" << std::endl;
		else
		{
			contacts[current_index].set_darkest_secret(input);
			break;
		}
	}
	current_index = (current_index + 1) % 8;
	std::cout << "Contact added successfully!" << std::endl;
}

static std::string	truncate_string(std::string str)
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
			<< std::setw(10) << "Nick Name" << std::endl;
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
		std::istringstream iss(input);
		if (!(iss >> index) || !iss.eof())
		{
			std::cout << "Invalid index. Please try again!" << std::endl;
			continue ;
		}
		if (index >= 0 && index <= 7 && !contacts[index].get_first_name().empty())
		{
			std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
			std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
			std::cout << "Nick Name: " << contacts[index].get_nick_name() << std::endl;
			std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
			std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
			break;
		}
		else if (index == -1)
			break ;
		else
			std::cout << "Invalid index. Please try again!" << std::endl;
	}
}
