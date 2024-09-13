/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:40:21 by jtu               #+#    #+#             */
/*   Updated: 2024/09/12 14:18:14 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		current_index;
		
	public:
		PhoneBook(): current_index(0) {}
		void	add(void);
		void	search(void);
		void	display_contacts(void);
};

#endif
