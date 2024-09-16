/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:37:11 by jtu               #+#    #+#             */
/*   Updated: 2024/09/16 16:38:48 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie* heap_zombie = newZombie("HeapZombie");
	heap_zombie->announce();
	delete heap_zombie;
	
	randomChump("StackZombie");
	return (0);
}