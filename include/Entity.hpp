#pragma once

#include <inttypes.h>
#include <ncurses.h>

class Entity {
public:
	Entity(uint32_t x, uint32_t y, wchar_t glyph)
		: m_xpos(x), m_ypos(y), m_glyph(glyph) {}
	void render(WINDOW * context);
	bool overlap(uint32_t x, uint32_t y) const;

protected:
	uint32_t m_xpos, m_ypos;
	wchar_t m_glyph;
};

class Tile : public Entity {
public:
	Tile(uint32_t x, uint32_t y, wchar_t glyph, bool blocking)
		: Entity(x, y, glyph), blocking(blocking) {}
	const bool blocking;
};

class Creature : public Entity {
public:
	Creature(uint32_t x, uint32_t y, wchar_t glyph)
		: Entity(x, y, glyph) {}

	void move_from(int xoff, int yoff) { m_xpos += xoff; m_ypos += yoff; }
	void move_to(int x, int y) { m_xpos = x; m_ypos = y; }

};

class Player : public Creature {
public:
	Player(uint32_t x, uint32_t y, wchar_t glyph) : Creature(x, y, glyph) {}
};