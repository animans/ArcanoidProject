#pragma once
#include <SFML/Graphics.hpp>
const int WIDTH = 200;
const int HIGHT = 320;
const float SPEED = 0.01;
class Platform : public sf::Drawable {
private:
    bool life;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(platf);
    }
public:
    float xl;
    float xr;
    float y;
    sf::RectangleShape platf;
    Platform();
    sf::Vector2f getPosition();
    void setxxy(float len);
    void setPlatf(int w, int h);
    void move(float time);
    bool checkWall(float xx);
    void updateGame(float);
};

