#pragma once

#include <vector>
#include <inttypes.h>
#include <ncurses.h>

#include "Entity.hpp"

class GameMap {
public:
	GameMap(WINDOW * window, Player player, uint32_t width, uint32_t height);
	GameMap(WINDOW * window, Player player, uint32_t width, uint32_t height, char filler);
	void render();
	inline std::vector<wchar_t> get_tiles() const { return m_tiles; }
	WINDOW * get_window() { return m_window; }
	void change_tile(uint32_t x, uint32_t y, wchar_t replacement) { m_tiles[x * y] = replacement; }
	void handle_input();

private:
	WINDOW * m_window = nullptr;
	Player m_player;
	uint32_t m_width, m_height;
	std::vector<wchar_t> m_tiles;
};