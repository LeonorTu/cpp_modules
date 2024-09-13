/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:19:38 by jtu               #+#    #+#             */
/*   Updated: 2024/09/13 17:22:24 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie*	horde = NULL;

	if (N <= 0)
		return (0);
	horde = new Zombie[N];
	while (--N >= 0)
	{
		horde[N].set_zombie_name(name);
	}
	return (horde);
}
