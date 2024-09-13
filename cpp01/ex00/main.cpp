/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:37:11 by jtu               #+#    #+#             */
/*   Updated: 2024/09/13 16:03:10 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	// Create a zombie on the heap
	Zombie* heap_zombie = newZombie("HeapZombie");
	heap_zombie->announce();
	delete heap_zombie; // Manually delete to avoid memory leak

	// Create a zombie on the stack
	randomChump("StackZombie");

	return 0;
}