#include <iostream>
#include <fstream>

#include "Logger.hpp"

void create(char* filename) {
	std::ofstream file;
	file.open(filename);
	Logger::Inform("Succesfully created ", filename);
	file.close();
}

void open(char* filename) {
	char op;
	std::ifstream file(filename);
	if (file.fail()) {
		Logger::Warn("File does not exist, or is outside this programs permissions.");
		Logger::Notify("Would you like to create ", filename, "? (y/n)");
		std::cin >> op;
		if (op == 'y' || op == 'Y') {
			Logger::Inform("Creating ", filename);
			file.close();
			create(filename);
			return;
		}
		else if (op == 'n' || op == 'N') {
			file.close();
			Logger::Error("Failed to obtain a suitable file to edit.");
		}
		else {
			file.close();
			Logger::Error("Invalid response.");
		}
	}
		
	std::cout << file.rdbuf();
	std::cin >> op;
	file.close();
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