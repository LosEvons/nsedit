#include "Board.hpp"

GameMap::GameMap(WINDOW * window, Player player, uint32_t width, uint32_t height)
	: m_window(window), m_player(player), m_width(width), m_height(height) {
	for (int i = 0; i < width * height; i++) {
		m_tiles.push_back('?');
	}
}

GameMap::GameMap(WINDOW * window, Player player, uint32_t width, uint32_t height, char filler)
	: m_window(window), m_player(player), m_width(width), m_height(height) {
	for (int i = 0; i < width * height; i++) {
		m_tiles.push_back(filler);
	}
}

void GameMap::render() {
	box(m_window, 0, 0);
	uint32_t x, y;
	for (x = 1; x < m_width; x++) {
		for (y = 1; y < m_height; y++) {
			if (m_player.overlap(x, y)) m_player.render(m_window);
			else mvwaddch(m_window, y, x, m_tiles[x * y]);
		}
	}
	wrefresh(m_window);
}

void GameMap::handle_input() {
	int c = wgetch(m_window);
	switch(c){
		case 'w':
			m_player.move_from(0, -1);
			break;
		case 's':
			m_player.move_from(0, 1);
			break;
		case 'd':
			m_player.move_from(1, 0);
			break;
		case 'a':
			m_player.move_from(-1, 0);
			break;

		default:
			break;
	}
}