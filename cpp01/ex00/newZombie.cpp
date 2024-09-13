/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:48:13 by jtu               #+#    #+#             */
/*   Updated: 2024/09/13 15:43:17 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*new_zombie = NULL;
	if( !(new_zombie  = new Zombie(name) ))
	{
		std::cout << "Error: out of memory." << std::endl;
		exit (1);
	}
	return (new_zombie);
}
