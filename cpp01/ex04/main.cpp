/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:34:47 by jtu               #+#    #+#             */
/*   Updated: 2024/09/27 17:28:47 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of inputs" << std::endl;
		std::cerr << "Usage: ./" << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
}
