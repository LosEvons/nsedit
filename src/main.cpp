#include <iostream>
#include <fstream>

#include "Logger.hpp"

void open(char* filename) {
	std::ifstream file(filename);
	if (file.fail())
		Logger::Error("File does not exist, or is outside this programs permissions.");
	std::cout << file.rdbuf();
	
	int op;
	std::cin >> op;
	return;
}

int main(int argc, char *argv[]) {
	if (argc < 2)
		Logger::Error("Too few arguments.");
	else if (argc > 2)
		Logger::Error("Too many arguments.");

	open(argv[1]);

	return 0;
}