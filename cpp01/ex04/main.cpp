/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:34:47 by jtu               #+#    #+#             */
/*   Updated: 2024/12/13 15:49:15 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void	replaceFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream infile(filename);
	if (!infile.is_open()){
		std::cerr << "Failed to open the input file." << std::endl;
	}
	std::string outfilename = filename + ".replace";
	std::ofstream outfile(outfilename);
	if (!outfile.is_open()){
		std::cerr << "Failed to create the output file." << std::endl;
	}

	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	std::string result;
	size_t pos = 0;
	while (1){
		size_t s1_pos = content.find(s1, pos);
		if (s1_pos == std::string::npos)
			break;
		result.append(content, pos, s1_pos - pos);
		result += s2;
		pos = s1_pos + s1.length();
	}
	result += content.substr(pos);
	outfile << result;
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of inputs" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	replaceFile(filename, s1, s2);
	return (0);
}
