/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:30:43 by jtu               #+#    #+#             */
/*   Updated: 2024/09/19 14:36:27 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	return (type);
}

void	Weapon::setType(const std::string& new_type)
{
	type = new_type;
}
