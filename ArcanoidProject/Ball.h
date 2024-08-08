#pragma once
#include <SFML/Graphics.hpp>


class Ball : public sf::Drawable {
	
	sf::Vector2f v;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(circle);
	}
public:
	sf::CircleShape circle;
	Ball();
	void setSpeed(float x, float y);
	void move(float time);
	sf::Vector2f getPosition();
	float getRadius();
	void updateGame(float time);
};