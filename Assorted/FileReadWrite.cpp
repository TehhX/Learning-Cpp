#include <iostream>
#include <string>
#include <fstream>

void writeFile() {
	std::ofstream fileToWrite;
	fileToWrite.open ("writtenFile.txt");
	fileToWrite << "This file has been written to using Cpp.\n";
	fileToWrite.close();
}

void readFile() {
	std::ifstream fileToRead ("textFile.txt");
	
	if (fileToRead.is_open()) {
		std::string outputStr {};
		while (std::getline(fileToRead, outputStr)) {
			std::cout << outputStr << '\n';
		}
	}
	else
		std::cerr << "Error opening file \"textFile.txt\".\n";
}

int main() {
	writeFile();
	readFile();
	return 0;	
}