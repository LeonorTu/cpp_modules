/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:07:54 by jtu               #+#    #+#             */
/*   Updated: 2024/09/13 17:17:11 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void	set_zombie_name(std::string zombie_name);
		void	announce( void );
};

Zombie*	zombieHorde( int N, std::string name );

#endif