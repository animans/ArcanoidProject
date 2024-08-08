#include "Platform.h"

Platform::Platform() {
    life = true;
    setPlatf(WIDTH / 2, HIGHT - 40);

}

sf::Vector2f Platform::getPosition() {
    return platf.getPosition();
}

void Platform::setxxy(float len) {
    xl = platf.getPosition().x - len;
    xr = platf.getPosition().x + len;
    y = platf.getPosition().y + 5;
}

void Platform::setPlatf(int w, int h) {
    platf.setSize(sf::Vector2f(50.f, 10.f));
    platf.setOrigin(sf::Vector2f(25.f, 5.f));
    platf.setPosition(sf::Vector2f(w, h));
    platf.setFillColor(sf::Color::Blue);
    setxxy(25.f);
}

void Platform::move(float time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) or sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        float xx = xl - SPEED * time;
        if (!checkWall(xx)) {
            platf.setPosition(sf::Vector2f(platf.getPosition().x - SPEED * time, platf.getPosition().y));
            setxxy(25.f);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) or sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        float xx = xr + SPEED * time;
        if (!checkWall(xx)) {
            platf.setPosition(sf::Vector2f(platf.getPosition().x + SPEED * time, platf.getPosition().y));
            setxxy(25.f);
        }
    }
}

bool Platform::checkWall(float xx) {
    if (xx <= 10.f or xx >= 190.f)
        return true;
    return false;
}

void Platform::updateGame(float time) {
    move(time);
}