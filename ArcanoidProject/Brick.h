#pragma once
#include <SFML/Graphics.hpp>

static int map[] = {	1, 0, 1, 0, 1,
				0, 1, 0, 1, 0,
				1, 0, 1, 0, 1,
				0, 1, 0, 1, 0,
				1, 0, 1, 0, 1,
				0, 1, 0, 1, 0, };

class Brick : public sf::Drawable {
	int size;
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(body);
	}
public:
	sf::VertexArray body;
	Brick();
	void setBricks(int map[]);
};