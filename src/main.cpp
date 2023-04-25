#include <iostream>
#include <fstream>

#include "Logger.hpp"

// Functions
void clear_console();
void handle_file(char* filename);
std::fstream open(char* filename);
std::fstream create(char* filename);

/*-------------------------------------------------*/
int main(int argc, char *argv[]) {
	if (argc < 2)
		Logger::Error("Too few arguments.");
	else if (argc > 2)
		Logger::Error("Too many arguments.");

	handle_file(argv[1]);

	return 0;
}

std::fstream create(char* filename) {
	std::fstream file;
	file.open(filename, std::ios::in | std::ios::out);
	if (file.fail())
		Logger::Error("Failed to create new file: ", filename);
	Logger::Inform("Succesfully created ", filename);

	return file;
}

std::fstream open(char* filename) {
	char op;
	std::fstream file(filename, std::ios::in | std::ios::out);
	if (file.fail()) {
		file.close();
		Logger::Warn("File does not exist, or is outside this programs permissions.");
		Logger::Notify("Would you like to create ", filename, "? (y/n)");
		std::cin >> op;
		if (op == 'y' || op == 'Y') {
			Logger::Inform("Creating ", filename);
			return create(filename);
		}
		else if (op == 'n' || op == 'N') {
			Logger::Error("Failed to obtain a suitable file to edit.");
		}
		else {
			Logger::Error("Invalid response.");
		}
	}
		
	return file;
}

void handle_file(char* filename) {
	char op;
	std::fstream file = open(filename);
	std::cout << file.rdbuf();
	std::cin >> op;
	file.close();
}

void clear_console(){
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}
