/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:40:21 by jtu               #+#    #+#             */
/*   Updated: 2024/09/10 13:52:26 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string darkest_secret;

	public:
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nick_name();
		std::string get_phone_number();
		std::string get_darkest_secret();
		void set_first_name(std::string name);
		void set_last_name(std::string name);
		void set_nick_name(std::string name);
		void set_phone_number(std::string number);
		void set_darkest_secret(std::string secret);
};

class	Phonebook
{
	private:
		Contact	contacts[8];
		int		current_index;
	public:
		Phonebook(): current_index(0) {}

		void	add(void);
		void	search(void);
		void	display_contacts(void);
};

#endif
