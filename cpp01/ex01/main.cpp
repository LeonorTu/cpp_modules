/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:07:58 by jtu               #+#    #+#             */
/*   Updated: 2024/09/16 16:39:27 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int		N = 5;
	Zombie	*horde = zombieHorde(N, "HordeZombie");

	if (horde != nullptr)
	{
		for (int i = 0; i < N; ++i)
			horde[i].announce();
	}
	delete[] horde;
	return (0);
}
