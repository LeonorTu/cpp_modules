/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:07:58 by jtu               #+#    #+#             */
/*   Updated: 2024/09/09 15:50:11 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string	Contact::get_first_name()
{
	return first_name;
}

std::string	Contact::get_last_name()
{
	return last_name;
}

std::string	Contact::get_nick_name()
{
	return nick_name;
}

std::string	Contact::get_phone_number()
{
	return phone_number;
}

std::string	Contact::get_darkest_secret()
{
	return darkest_secret;
}

void	Contact::set_first_name(std::string name)
{
	first_name = name;
}

void	Contact::set_last_name(std::string name)
{
	last_name = name;
}

void	Contact::set_nick_name(std::string name)
{
	nick_name = name;
}

void	Contact::set_phone_number(std::string number)
{
	phone_number = number;
}

void	Contact::set_darkest_secret(std::string secret)
{
	darkest_secret = secret;
}
