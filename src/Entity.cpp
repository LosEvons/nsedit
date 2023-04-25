#include "Entity.hpp"

void Entity::render(WINDOW * context) {
	mvwaddch(context, m_ypos, m_xpos, m_glyph);
}

bool Entity::overlap(uint32_t x, uint32_t y) const {
	if ( x == m_xpos && y == m_ypos) 
		return true;
	else 
		return false;
}

