#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
	std::ifstream inputFile(filename);
	if (!inputFile) {
		std::cerr << "Failed to open input file: " << filename << std::endl;
		return;
	}

	std::ofstream outputFile(filename + ".replace");
	if (!outputFile) {
		std::cerr << "Failed to create output file: " << filename << ".replace" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}

	std::cout << "Replacement completed successfully!" << std::endl;
}

int main() {
	std::string filename;
	std::string s1;
	std::string s2;

	std::cout << "Enter the filename: ";
	std::cin >> filename;

	std::cout << "Enter the string to replace: ";
	std::cin >> s1;

	std::cout << "Enter the replacement string: ";
	std::cin >> s2;

	replaceInFile(filename, s1, s2);

	return 0;
}