/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:30:36 by jtu               #+#    #+#             */
/*   Updated: 2024/09/19 14:35:02 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class	HumanB
{
	private:
		Weapon*		weapon;
		std::string	name;

	public:
		HumanB(const std::string& name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon& new_weapon);
};

#endif