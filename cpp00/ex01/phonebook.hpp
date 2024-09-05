/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:40:21 by jtu               #+#    #+#             */
/*   Updated: 2024/09/05 16:21:44 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class	Phonebook
{
	private:
		Contact	contacts[8];
	public:
		void	add(void);
		void	search(void);
};

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
		std::string get_first_name()
		{
			return first_name;
		}
		std::string get_last_name()
		{
			return last_name;
		}
		std::string get_nick_name()
		{
			return nick_name;
		}
		std::string get_phone_number()
		{
			return phone_number;
		}
		std::string get_darkest_secret()
		{
			return darkest_secret;
		}
		void set_first_name(std::string name)
		{
			first_name = name;
		}
		void set_last_name(std::string name)
		{
			last_name = name;
		}
		void set_phone_number(std::string number)
		{
			phone_number = number;
		}
		void set_darkest_secret(std::string secret)
		{
			darkest_secret = secret;
		}
};


#endif