#include "Brick.h"

Brick::Brick() {
	size = 0;
	body.resize(0);
	body.setPrimitiveType(sf::Triangles);
	setBricks(map);
}

void Brick::setBricks(int map[]) {
	for (int i = 0; i < 30; ++i) {
		if (map[i] == 1) {
			body.resize(size + 6);
			size += 6;
			if (i % 2 == 0) {
				
				body[size - 6    ].position = sf::Vector2f(10.f + i%5 * 35, 10.f + 10 * (i / 5));
				body[size - 6 + 1].position = sf::Vector2f(10.f + i % 5 * 35 + 40, 10.f + 10 * (i / 5));
				body[size - 6 + 2].position = sf::Vector2f(10.f + i % 5 * 35, 10.f + 10 * (i / 5) + 10);
				body[size - 6 + 3].position = sf::Vector2f(10.f + i % 5 * 35 + 40, 10.f + 10 * (i / 5));
				body[size - 6 + 4].position = sf::Vector2f(10.f + i % 5 * 35, 10.f + 10 * (i / 5) + 10);
				body[size - 6 + 5].position = sf::Vector2f(10.f + i % 5 * 35 + 40, 10.f + 10 * (i / 5) + 10);
			}
			else {
				body[size - 6    ].position = sf::Vector2f(35.f + i % 5 * 35, 35.f + 10 * (i / 5));
				body[size - 6 + 1].position = sf::Vector2f(35.f + i % 5 * 35 + 40, 35.f + 10 * (i / 5));
				body[size - 6 + 2].position = sf::Vector2f(35.f + i % 5 * 35, 35.f + 10 * (i / 5) + 10);
				body[size - 6 + 3].position = sf::Vector2f(35.f + i % 5 * 35 + 40, 35.f + 10 * (i / 5));
				body[size - 6 + 4].position = sf::Vector2f(35.f + i % 5 * 35, 35.f + 10 * (i / 5) + 10);
				body[size - 6 + 5].position = sf::Vector2f(35.f + i % 5 * 35 + 40, 35.f + 10 * (i / 5) + 10);
			}
			for (int j = 0; j < 6; ++j) {
				body[size - 6 + j].color = sf::Color::Green;
			}
		}
	}
}
