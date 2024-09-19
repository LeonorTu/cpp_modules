/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:30:46 by jtu               #+#    #+#             */
/*   Updated: 2024/09/19 14:38:12 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class	Weapon
{
	private:
		std::string	type;

	public:
		Weapon(const std::string& type);
		~Weapon();
		const std::string&	getType();
		void			setType(const std::string &new_type);
};

#endif
