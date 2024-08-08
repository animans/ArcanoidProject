#include "Platform.h"
#include "Brick.h"
#include "Ball.h"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HIGHT), "Arcanoid");

    sf::RectangleShape wall1(sf::Vector2f(10.f, HIGHT));
    wall1.setFillColor(sf::Color(128, 128, 128));

    sf::RectangleShape wall2(sf::Vector2f(10.f, HIGHT));
    wall2.setFillColor(sf::Color(128, 128, 128));
    wall2.setPosition(sf::Vector2f(WIDTH - 10.f, 0.f));

    sf::RectangleShape wall3(sf::Vector2f(WIDTH, 10.f));
    wall3.setFillColor(sf::Color(128, 128, 128));
    sf::RectangleShape rect(sf::Vector2f(1000.f, 10.f));
    rect.setPosition(sf::Vector2f(10, 10));

    Platform platf;
    Brick bricks;
    Ball ball;
    sf::Clock clock;
    ball.setSpeed(0.f, -0.01f);
    while (window.isOpen())
    {
        sf::Time time = clock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float elapsed = time.asMicroseconds() / 100;
        platf.updateGame(elapsed);
        ball.updateGame(elapsed);
        
        if (ball.circle.getGlobalBounds().intersects(rect.getLocalBounds())) ball.setSpeed(0.f, 0.01f);
        if (ball.circle.getGlobalBounds().intersects(bricks.body.getBounds())) ball.setSpeed(0.f, 0.01f);
        if (ball.circle.getGlobalBounds().intersects(platf.platf.getGlobalBounds())) ball.setSpeed(0.f, -0.01f);

        window.clear();
        window.draw(wall1);
        window.draw(wall2);
        window.draw(wall3);
        window.draw(platf);
        window.draw(bricks);
        window.draw(ball);
        window.display();
    }

    return EXIT_SUCCESS;
}