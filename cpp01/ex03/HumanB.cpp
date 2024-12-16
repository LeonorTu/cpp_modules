/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:30:41 by jtu               #+#    #+#             */
/*   Updated: 2024/12/16 15:41:40 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name):name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (!weapon->getType().empty())
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " is not armed" << std::endl;
}

void	HumanB::setWeapon(Weapon& new_weapon)
{
	weapon = &new_weapon;
}
