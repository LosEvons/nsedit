#include <memory>
#include <iostream>
#include <ncurses.h>

#include "Board.hpp"
#include "Entity.hpp"
#include "Logger.hpp"

void init_curses() {
	Logger::Inform("Starting program...");
	initscr();
	cbreak();
	noecho();
	Logger::Inform("Curses initialized.");
}

void uninit_curses() {
	Logger::Warn("Exiting program...");
	endwin();
	Logger::Warn("Window closed.");
}

int main(int argc, char ** argv) {
	init_curses();
	Player player(12, 12, '@');
	std::unique_ptr<GameMap> board = std::make_unique<GameMap>(newwin(25, 25, 0, 0), player, 24, 24, '.');
	//std::unique_ptr<Player> player = std::make_unique<Player>(board.get(), 12, 12, '@');

	while (true) {
	board->render();
	refresh();
	board->handle_input();
	}

	uninit_curses();
	return 0;
}