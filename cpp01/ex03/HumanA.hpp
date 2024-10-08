/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:29:19 by jtu               #+#    #+#             */
/*   Updated: 2024/09/19 14:38:49 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class	HumanA
{
	private:
		Weapon		weapon;
		std::string	name;

	public:
		HumanA(const std::string& name, const Weapon& weapon);
		~HumanA();
		void	attack();
};

#endif
