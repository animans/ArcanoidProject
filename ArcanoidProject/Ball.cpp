#include "Ball.h"
const int WIDTH = 200;
const int HIGHT = 320;
Ball::Ball() {
	circle.setRadius(5);
	
	circle.setOrigin(sf::Vector2f(5, 5));
	circle.setPosition(sf::Vector2f(WIDTH / 2, HIGHT - 50));
	circle.setFillColor(sf::Color::Color(198, 198, 198));
	setSpeed(0.f, 0.f);
}

void Ball::setSpeed(float x, float y) {
	circle.getGlobalBounds();
	v = sf::Vector2f(x, y);
}

void Ball::move(float time) {
	circle.setPosition(circle.getPosition().x + v.x * time, circle.getPosition().y + v.y * time);
}

sf::Vector2f Ball::getPosition() {
	return circle.getPosition();
}

float Ball::getRadius() {
	return circle.getRadius();
}

void Ball::updateGame(float time) {
	move(time);
}