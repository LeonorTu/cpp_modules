#include "replace.hpp"

void replace(const std::string& filename, const std::string& s1, const std::string& s2)
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
