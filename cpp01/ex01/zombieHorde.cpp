/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:19:38 by jtu               #+#    #+#             */
/*   Updated: 2024/09/16 16:36:36 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie*	horde = NULL;

	if (N <= 0)
		return (0);
	horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].set_zombie_name(name);
	return (horde);
}
