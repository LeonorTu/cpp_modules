/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:12:13 by jtu               #+#    #+#             */
/*   Updated: 2024/07/02 15:56:19 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char)toupper(argv[i][j]) ;
		}
	}
	std::cout << std::endl;
	return (0);
}
